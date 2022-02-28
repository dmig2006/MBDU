#include "supportmanager.h"

SupportManager* SupportManager::mSupportManager = 0;

SupportManager* SupportManager::getSingletonPtr()
{
    if (!mSupportManager)
        mSupportManager = new SupportManager();
    return mSupportManager;
}

//@return values element xml file
std::string SupportManager::getValueXml(const char *pNameElement, TiXmlDocument document)
{
    TiXmlNode* node     = 0;
    TiXmlElement* todoElement   = 0;
    TiXmlElement* itemElement   = 0;
    //First ToDo element
    node    = document.FirstChild("ConfigurationParameters");
    todoElement = node->ToElement();
    node    = todoElement->FirstChildElement(); // This skips the "PDA" comment.
    itemElement = node->ToElement();
    std::string str = std::string(itemElement->Attribute(pNameElement));
    return str;
}

TiXmlDocument SupportManager::loadFileXml(const char *pFileName)
{
    TiXmlDocument document(pFileName);
    if (!document.LoadFile())
    {
        std::cerr << "XML file: " << pFileName <<  "error\n";
        return 0;
    }
    return document;
}

TableFile* SupportManager::loadTable(const char *pFileName, WeaponType pWeaponType)
{
    TableFile *lTableFile = 0;
    std::fstream file;
    file.open(pFileName, std::ios::in);
    if (!file)
        return 0;
    lTableFile = new TableFile();
    switch (pWeaponType)
    {
        case WEAPON_KORD:
            for (int i = 0; i < 20; ++i)
            {
                int range;
                unsigned char degree;
                unsigned char arcminute;
                unsigned char pressure;
                unsigned char temperature;
                unsigned char headwind_4;
                unsigned char headwind_10;
                double crosswind_4;
                double crosswind_6;
                double crosswind_8;
                double crosswind_10;
                double derivation;

                file.read((char*)&range,        sizeof(range)       );
                file.read((char*)&degree,       sizeof(degree)      );
                file.read((char*)&arcminute,    sizeof(arcminute)   );
                file.read((char*)&pressure,     sizeof(pressure)    );
                file.read((char*)&temperature,  sizeof(temperature) );
                file.read((char*)&headwind_4,   sizeof(headwind_4)  );
                file.read((char*)&headwind_10,  sizeof(headwind_10) );
                file.read((char*)&crosswind_4,  sizeof(crosswind_4) );
                file.read((char*)&crosswind_6,  sizeof(crosswind_6) );
                file.read((char*)&crosswind_8,  sizeof(crosswind_8) );
                file.read((char*)&crosswind_10, sizeof(crosswind_10));
                file.read((char*)&derivation,   sizeof(derivation)  );

                lTableFile->Range[i]              = range;
                lTableFile->Gradus[i]             = degree;
                lTableFile->Minuta[i]             = arcminute;
                lTableFile->Wind[i]               = 0;
                lTableFile->CrossWind10[i]        = crosswind_10;
                lTableFile->CrossWind8[i]         = crosswind_8;
                lTableFile->CrossWind6[i]         = crosswind_6;
                lTableFile->CrossWind4[i]         = crosswind_4;
                lTableFile->Derivation[i]         = derivation;
                lTableFile->LongitudinalWind10[i] = headwind_10;
                lTableFile->LongitudinalWind4[i]  = headwind_4;
                lTableFile->Pressure[i]           = pressure;
                lTableFile->Thermo[i]             = temperature;
            }
            break;
    }
    return lTableFile;
}


JustFile* SupportManager::loadJust(const char *pFileName)
{
    std::fstream file;
    file.open(pFileName, std::ios::in);
    JustFile* lJustFile = new JustFile();
    if (!file)
    {
        memset(&lJustFile->mJustValues, 0, sizeof(lJustFile->mJustValues));
    }
    else
    {
        int len = sizeof(lJustFile->mJustValues) / sizeof(long);
        for (int i = 0; i < len; ++i)
            file >> lJustFile->mJustValues[i];
        file.close();
    }
    return lJustFile;
}

bool SupportManager::saveJust(JustFile *lJustFile, const char *pFileName)
{
    std::fstream file;
    file.open(pFileName, std::ios::out);
    if (!file)
          return false;
    int len = sizeof(lJustFile->mJustValues) / sizeof(long);
    for (int i = 0; i < len; ++i)
        file << lJustFile->mJustValues[i] << std::endl;
    file.close();
    return true;
}
