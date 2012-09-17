#ifndef _ESM_LAND_H
#define _ESM_LAND_H

#include <libs/platform/stdint.h>

#include "record.hpp"
#include "esm_common.hpp"

namespace ESM
{
/*
 * Landscape data.
 */

struct Land : public Record
{
    Land();
    ~Land();

    int mFlags; // Only first four bits seem to be used, don't know what
    // they mean.
    int mX, mY; // Map coordinates.

    // File context. This allows the ESM reader to be 'reset' to this
    // location later when we are ready to load the full data set.
    ESMReader* mEsm;
    ESM_Context mContext;

    bool mHasData;
    int mDataTypes;
    bool mDataLoaded;

    enum
    {
        DATA_VNML = 1,
        DATA_VHGT = 2,
        DATA_WNAM = 4,
        DATA_VCLR = 8,
        DATA_VTEX = 16
    };

    // number of vertices per side
    static const int LAND_SIZE = 65;

    // cell terrain size in world coords
    static const int REAL_SIZE = 8192;

    // total number of vertices
    static const int LAND_NUM_VERTS = LAND_SIZE * LAND_SIZE;

    static const int HEIGHT_SCALE = 8;

    //number of textures per side of land
    static const int LAND_TEXTURE_SIZE = 16;

    //total number of textures per land
    static const int LAND_NUM_TEXTURES = LAND_TEXTURE_SIZE * LAND_TEXTURE_SIZE;

#pragma pack(push,1)
    struct VHGT
    {
        float mHeightOffset;
        int8_t mHeightData[LAND_NUM_VERTS];
        short mUnknown1;
        char mUnknown2;
    };
#pragma pack(pop)

    typedef uint8_t VNML[LAND_NUM_VERTS * 3];

    struct LandData
    {
        float mHeightOffset;
        float mHeights[LAND_NUM_VERTS];
        VNML mNormals;
        uint16_t mTextures[LAND_NUM_TEXTURES];

        bool mUsingColours;
        char mColours[3 * LAND_NUM_VERTS];
        int mDataTypes;

        void save(ESMWriter &esm);
    };

    LandData *mLandData;

    void load(ESMReader &esm);
    void save(ESMWriter &esm);

    int getName() { return REC_LAND; }

    /**
     * Actually loads data
     */
    void loadData();

    /**
     * Frees memory allocated for land data
     */
    void unloadData();

    private:
        Land(const Land& land);
        Land& operator=(const Land& land);
};

}
#endif
