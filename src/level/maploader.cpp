#include "level/maploader.h"
#include <fstream>
#include <iostream>

bool MapLoader::load(const char* filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "ERRO CRITICO: Nao foi possivel abrir o arquivo " << filename << std::endl;
        return false;
    }

    std::string line;
    mapData.clear();
    height = 0;
    width = 0;

    while (std::getline(file, line)) {

        // remove \r se o arquivo vier do Windows
        if (!line.empty() && line.back() == '\r')
            line.pop_back();

        // ignora linhas vazias ou comentários
        if (line.empty() || line[0] == '#')
            continue;

        // detecta spawn '9'
        for (int x = 0; x < (int)line.size(); x++) {
            if (line[x] == '9') {
                playerStartX = (float)x;
                playerStartZ = (float)height;
                line[x] = '0';
            }
        }

        mapData.push_back(line);
        if ((int)line.size() > width) width = (int)line.size();
        height++;
    }

    file.close();
    return (height > 0 && width > 0);
}

//bool MapLoader::isWall(int x, int z) const//
//{
    //if (x < 0 || z < 0 || x >= width || z >= height)
      //  return false;

    //char c = mapData[z][x];
    //return (c == '1' || c == '2');
//}

//bool MapLoader::isExteriorFace(int x, int z, int dx, int dz) const
//{
    //int nx = x + dx;
    //int nz = z + dz;

    // fora do mapa = exterior
   // if (nx < 0 || nz < 0 || nx >= width || nz >= height)
     //   return true;

    // se o vizinho não é parede, é exterior
    //return !isWall(nx, nz);
//}
