#include "Map.hpp"
#include <ctime>

int main()
{
    srand(time(nullptr));
    Map m(500,"biome.txt");
    m.initMap();
    m.remplissage();
    m.save("../map.txt","../mapObstacle.txt");
    return 0;
}
