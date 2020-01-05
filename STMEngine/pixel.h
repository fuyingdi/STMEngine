namespace STM{
    struct Pixel
    {
        union
        {
            uint32_t n = 0xFF000000;
            struct
            {
                uint8_t r;	uint8_t g;	uint8_t b;	uint8_t a;
            };
        };

        Pixel();
        Pixel(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);
        Pixel(uint32_t p);

        enum Mode { NORMAL, MASK, ALPHA, CUSTOM };

        bool operator==(const Pixel& p) const;
        bool operator!=(const Pixel& p) const;
    };

    const Pixel WHITE(255, 255, 255);

    enum rcode
    {
        FAIL = 0,
        OK = 1,
        NO_FILE = -1,
    };

	Pixel::Pixel()
	{
		r = 0; g = 0; b = 0; a = 255;
	}

	Pixel::Pixel(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
	{
		r = red; g = green; b = blue; a = alpha;
	}

	Pixel::Pixel(uint32_t p)
	{
		n = p;
	}

	bool Pixel::operator==(const Pixel& p) const
	{
		return n == p.n;
	}

	bool Pixel::operator!=(const Pixel& p) const
	{
		return n != p.n;
	}

};

