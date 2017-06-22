#include <iostream>

class Sky
{
public:
	Sky(int stars = 0)
		: m_stars(stars)
	{}

    int getStars() const
	{
		return m_stars;
	}

    void setStars(int n)
	{
		m_stars = n;
	}

private:
	int m_stars;
};

class BlueSky : public Sky
{
public:
	BlueSky(int stars = 0)
		: Sky(stars)
	{}
};

class NightSky : public Sky
{
public:
	NightSky(int stars = 0)
		: Sky(stars)
	{}
};

class BlueNightSky : public BlueSky
{
public:
    BlueNightSky(int stars = 0)
        : BlueSky(stars)
    {}
};

void readInput(BlueNightSky& blueNightSky)
{
	int n = 0;
	std::cin >> n;

    blueNightSky.setStars(n);
}

int getAmountOfStars(const BlueNightSky& blueNightSky)
{
    return blueNightSky.getStars();
}

int main(int argc, char** argv)
{
	BlueNightSky blueNightSky;

	readInput(blueNightSky);

	std::cout << getAmountOfStars(blueNightSky) << std::endl;

	return 0;
}
