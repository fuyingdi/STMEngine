#include<string>
#include<map>
#include<iostream>
#include "pixel.h"

namespace STM{

class ResourcePack
{
    public:
        ResourcePack();
        ~ResourcePack();
        struct sEntry : public std::streambuf {
            uint32_t nID, nFileOffset, nFileSize; uint8_t* data; void _config() { this->setg((char*)data, (char*)data, (char*)(data + nFileSize)); }
        };
    public:
        STM::rcode AddToPack(std::string sFile);
    public:
        STM::rcode SavePack(std::string sFile);
        STM::rcode LoadPack(std::string sFile);
        STM::rcode ClearPack();
    public:
        STM::ResourcePack::sEntry GetStreamBuffer(std::string sFile);

    private:
        std::map<std::string, sEntry> mapFiles;
};
class Sprite
{
    public:
        Sprite();
        Sprite(std::string sImageFile);
        Sprite(std::string sImageFile, STM::ResourcePack *pack);
        Sprite(int32_t w, int32_t h);
        ~Sprite();
    public:
        STM::rcode LoadFromFile(std::string sImageFile, STM::ResourcePack *pack = nullptr);
        STM::rcode LoadFromPGESprFile(std::string sImageFile, STM::ResourcePack *pack = nullptr);
        STM::rcode SaveToPGESprFile(std::string sImageFile);
    public:
        int32_t width = 0;
        int32_t height = 0;
        enum Mode { NORMAL, PERIODIC };
    public:
        void SetSampleMode(STM::Sprite::Mode mode = STM::Sprite::Mode::NORMAL);
        Pixel GetPixel(int32_t x, int32_t y);
        bool  SetPixel(int32_t x, int32_t y, Pixel p);

        Pixel Sample(float x, float y);
        Pixel SampleBL(float u, float v);
        Pixel* GetData();
    private:
        Pixel *pColData = nullptr;
        Mode modeSample = Mode::NORMAL;
};
}