#ifndef SUPPORT_MANAGER_H
#define SUPPORT_MANAGER_H
/*****************************************************************************/
/*** Support manager                                                       ***/
/*****************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ios>
#include <iostream>
#include <vector>
#include <unistd.h>

//support xml files config-----------------------------------------------------
#include "tinyxml.h"
#include "tinystr.h"

#include "weapon.enum.h"			// Controller

#define FILE_TABLE_KORD "config/ballistic_tables/kord.btb"

#define FILE_JUST       "config/just.cfg"


const float cB32Times[21] = {
    0.00,  //    0
    0.13,  //  100
    0.26,  //  200
    0.40,  //  300
    0.55,  //  400
    0.70,  //  500
    0.86,  //  600
    1.03,  //  700
    1.21,  //  800
    1.40,  //  900
    1.61,  // 1000
    1.83,  // 1100
    2.06,  // 1200
    2.31,  // 1300
    2.58,  // 1400
    2.86,  // 1500
    3.16,  // 1600
    3.47,  // 1700
    3.79,  // 1800
    4.12,  // 1900
    4.47   // 2000
};

struct TableFile {
    int Range[20];
    int Gradus[20];
    int Minuta[20];
    double CrossWind10[20];
    double CrossWind8[20];
    double CrossWind6[20];
    double CrossWind4[20];
    double Wind[20];
    double Derivation[20];
    double LongitudinalWind10[20];
    double LongitudinalWind4[20];
    double Pressure[20];
    double Thermo[20];
};

struct JustFile {
    long mJustValues[24];
};

class SupportManager
{
    static SupportManager* mSupportManager;

    SupportManager() {}

public:
    static SupportManager* getSingletonPtr();
    //get values
    std::string getValueXml(const char *pNameElement, TiXmlDocument document);
    //loading data
    TiXmlDocument loadFileXml(const char *pFileName);
    TableFile* loadTable(const char *pFileName, WeaponType pWeaponType);
    JustFile* loadJust(const char *pFileName);
    //save data
    bool saveJust(JustFile *lJustFile, const char *pFileName);
};

#endif // SUPPORT_MANAGER_H
