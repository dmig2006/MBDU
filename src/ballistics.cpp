#include "ballistics.h"

bool Ballistics::calculate(WeaponType pWeaponType, long pRange, long pThermo,
                           long pPressure, long pWindX, long pWindY)
{
    TableFile *bal_table = CfgManager::getSingletonPtr()->getAmendment(pWeaponType);
    if (!bal_table)
    {
        std::cerr << "Ballistic table not found\n";
        return false;
    }

    mAmendmentX = mAmendmentY = 0;

    if (pRange < 100)
        return true;

    double kx = DEGREE_TO_CENTIDEGREE;
    double ky = DEGREE_TO_CENTIDEGREE;
    double my = ARCMINUTE_TO_CENTIDEGREE;
    long tmp_range = 0;
    long yi1;
    long yi2;
    int num = 0;

    if (pRange > 2000)
        pRange = 2000;

    if (pThermo < -40)
        pThermo = -40;
    if (pThermo > 60)
        pThermo = 60;

    if (pPressure < 400)
        pPressure = 400;
    if (pPressure > 800)
        pPressure = 800;

    switch (pWeaponType)
    {
        case WEAPON_KORD:   /* Calculate Amendment for KORD */
            {
            tmp_range = 10000;
            for (int i = 0; i < 20; ++i)
            {
                long tmp = abs(pRange - bal_table->Range[i]);
                if (tmp <= tmp_range)
                {
                    tmp_range = tmp;
                    num = i;
                    if (!tmp_range)
                        break;
                }
            }

        if (pWindX < -9)
            mAmendmentX += lrint(-0.06 * kx * bal_table->CrossWind10[num]);
        else
            if (pWindX >= -9 && pWindX < -7)
                mAmendmentX += lrint(-0.06 * kx * bal_table->CrossWind8[num]);
            else
                if (pWindX >= -7 && pWindX < -5)
                    mAmendmentX += lrint(-0.06 * kx * bal_table->CrossWind6[num]);
                else
                    if (pWindX >= -5 && pWindX < -2)
                        mAmendmentX += lrint(-0.06 * kx * bal_table->CrossWind4[num]);
                    else
                        if (pWindX >= -2 && pWindX <= 2)
                            mAmendmentX = 0;
                        else
                            if (pWindX > 2 && pWindX <= 5)
                                mAmendmentX += lrint(0.06 * kx * bal_table->CrossWind4[num]);
                            else
                                if (pWindX > 5 && pWindX <= 7)
                                    mAmendmentX += lrint(0.06 * kx * bal_table->CrossWind6[num]);
                                 else
                                    if (pWindX > 7 && pWindX <= 9)
                                        mAmendmentX += lrint(0.06 * kx * bal_table->CrossWind8[num]);
                                     else
                                        mAmendmentX += lrint(0.06 * kx * bal_table->CrossWind10[num]);
                                        mAmendmentX += lrint(0.06 * kx * bal_table->Derivation[num]);

        if (pWindY < -7)
            mAmendmentY = lrint(-ky * atan(bal_table->LongitudinalWind10[num]
                                           / (double)bal_table->Range[num])
                                * 180.0 / M_PI);
        else
            if (pWindY >= -6 && pWindY < -2)
                mAmendmentY = lrint(-ky * atan(bal_table->LongitudinalWind4[num]
                                               / (double)bal_table->Range[num])
                                  * 180.0 / M_PI);
             else
                if (pWindY >= -2 && pWindY <= 2)
                    mAmendmentY = 0;
                else
                    if (pWindY > 2 && pWindY <= 7)
                        mAmendmentY = lrint(ky * atan(bal_table->LongitudinalWind4[num]
                                                    / (double)bal_table->Range[num])
                                            * 180.0 / M_PI);
                     else
                        mAmendmentY = lrint(ky * atan(bal_table->LongitudinalWind10[num]
                                                / (double)bal_table->Range[num])
                                        * 180.0 / M_PI);

                        yi1 = (pPressure - 750) * bal_table->Pressure[num] / 10;
                        yi2 = (15 - pThermo) * bal_table->Thermo[num] / 10;

                        tmp_range = 10000;
                        for (int i = 0; i < 20; ++i)
                        {
                            long tmp = abs(pRange + yi1 + yi2 - bal_table->Range[i]);
                            if (tmp <= tmp_range)
                            {
                                tmp_range = tmp;
                                num = i;
                                if (tmp_range == 0)
                                    break;
                            }
                        }

        mAmendmentY += lrint((double)bal_table->Gradus[num] * ky
                             + (double)bal_table->Minuta[num] * my);
        }
            break;
        default:
            break;
       } // switch

    return true;
}
