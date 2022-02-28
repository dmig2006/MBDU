#include "aimlist.h"

AimList* AimList::mAimList = 0;

AimList* AimList::getSingletonPtr()
{
    if (!mAimList)
        mAimList = new AimList();
    return mAimList;
}

void AimList::push(Aim *pAim)
{
    mMutex.lock();
    aims.push_back(pAim);
    mMutex.unlock();
}

Aim* AimList::pop()
{
    mMutex.lock();
    if (aims.size() > 0)
    {
        Aim *lAim = aims.front();
        aims.pop_front();
        mMutex.unlock();
        return lAim;
    }
    else
    {
        mMutex.unlock();
        return 0;
    }
}

void AimList::remove(int id)
{
    mMutex.lock();
    if (aims.size() > 0)
    {
        aims.removeOne(aims[id]);
        mMutex.unlock();
    }
    else
    {
        mMutex.unlock();
    }
}

void AimList::clear()
{
    mMutex.lock();
    aims.clear();
    mMutex.unlock();
}

void AimList::makeAllAimsAlive()
{
    mMutex.lock();
    for (int i = 0; i < aims.size(); ++i)
        aims[i]->isAlive = true;
    mMutex.unlock();
}

void AimList::sortAims()
{
    Aim *lAimBuffer = 0;
    sortedAims.clear();

    for (int i = 0; i < aims.size(); ++i)
    {
        if (aims[i]->mActive)
            sortedAims.push_back(aims[i]);
    }

    for (int i = sortedAims.size() - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            int range_1 = 0;
            int range_2 = 0;
            if (fmod((double)sortedAims[j]->mPositionX,
                     360 * DEGREE_TO_CENTIDEGREE) >= 180 * DEGREE_TO_CENTIDEGREE)
            {
                range_1 = fmod((double)sortedAims[j]->mPositionX,
                               360 * DEGREE_TO_CENTIDEGREE)
                          - 360 * DEGREE_TO_CENTIDEGREE;
            }
            else
            {
                range_1 = fmod((double)sortedAims[j]->mPositionX,
                               360 * DEGREE_TO_CENTIDEGREE);
            }

            if (fmod((double)sortedAims[j + 1]->mPositionX,
                     360 * DEGREE_TO_CENTIDEGREE) >= 180 * DEGREE_TO_CENTIDEGREE)
            {
                range_2 = fmod((double)sortedAims[j + 1]->mPositionX,
                               360 * DEGREE_TO_CENTIDEGREE)
                          - 360 * DEGREE_TO_CENTIDEGREE;
            }
            else
            {
                range_2 = fmod((double)sortedAims[j + 1]->mPositionX,
                               360 * DEGREE_TO_CENTIDEGREE);
            }
            if (range_1 >= range_2)
            {
                lAimBuffer = sortedAims[j];
                sortedAims[j] = sortedAims[j + 1];
                sortedAims[j + 1] = lAimBuffer;
            }
        }
    }
}

void AimList::setTarget(int pTarget)
{
    mMutex.lock();
    mTarget = pTarget;
    mMutex.unlock();
}

void AimList::setAimBarrageLeft(Aim *pAim)
{
    mAimBarrageLeft = pAim;
}

void AimList::setAimBarrageRight(Aim *pAim)
{
    mAimBarrageRight = pAim;
}

int AimList::getTarget()
{   int tmp;
    mMutex.lock();
    tmp = mTarget;
    mMutex.unlock();
    return tmp;
}

int  AimList::getMaxTarget()
{
    int lTarget = 0;
    mMutex.lock();
    for (int i = 0; i < aims.size(); ++i)
        if (aims[i]->mTarget > lTarget)
            lTarget = aims[i]->mTarget;
    mMutex.unlock();
    return lTarget;
}

Aim* AimList::get(int pId)
{
    mMutex.lock();
    Aim *lAim = 0;
    if (pId >= 0 && pId < aims.size())
        lAim = aims[pId];
    mMutex.unlock();
    return lAim;
}

Aim* AimList::getByTarget(int pTarget)
{
    mMutex.lock();
    Aim *lAim = 0;
    for (int i = 0; i < aims.size(); ++i)
        if (aims[i]->mTarget == pTarget && lAim->mActive)
        {
            lAim = aims[i];
            break;
        }
    mMutex.unlock();
    return lAim;
}

Aim* AimList::getMinimal(long pCurrentPositionX)
{
    mMutex.lock();
    Aim *lAim = 0;
    long dist = 0;
    for (int i = 0; i < aims.size(); ++i)
        if (aims[i]->mActive && aims[i]->isAlive)
        {
            long posAimX = aims[i]->mPositionX;
            long posX = pCurrentPositionX;
            dist = abs(posAimX - posX);
            lAim = aims[i];
        }
    for (int i = 0; i < aims.size(); ++i)
        if (aims[i]->mActive && aims[i]->isAlive)
        {
            long posAimX = aims[i]->mPositionX;
            long posX = pCurrentPositionX;
            long ldist = abs(posAimX - posX);
            if (ldist < dist)
            {
                lAim = aims[i];
                dist = ldist;
            }
        }
    if (lAim)
        lAim->isAlive = false;
    mMutex.unlock();
    return lAim;
}

Aim* AimList::getMaxRight()
{
    mMutex.lock();
    Aim *lAim = 0;
    long dist = 0;
    for (int i = 0; i < aims.size(); ++i)
        if (aims[i]->mActive)
        {
            long ldist = aims[i]->mPositionX;
            if (ldist >= dist && ldist < 139264)
            {
                lAim = aims[i];
                dist = ldist;
            }
        }
    mMutex.unlock();
    return lAim;
}
