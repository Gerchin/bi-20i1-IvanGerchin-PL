#pragma once
#include <SFML/Graphics.hpp>

const int HEIGHT_MAP = 30;
const int WIDTH_MAP = 40;

sf::String TileMap[HEIGHT_MAP] = {
	"0000000000000000000000000000000000000000",
	"0     s                                0",
	"0   s    s                s            0",
	"0    s                                 0",
	"0                   s         s        0",
	"0        s                             0",
	"0                                      0",
	"0                                      0",
	"0        s        s                    0",
	"0                                 s    0",
	"0                                      0",
	"0                           s          0",
	"0       s                              0",
	"0                  s                   0",
	"0                                      0",
	"0       s                      s       0",
	"0                                      0",
	"0                                      0",
	"0           s        s        s        0",
	"0                                      0",
	"0                                      0",
	"0       s                    s         0",
	"0       s                    s         0",
	"0       s                    s         0",
	"0       s                    s         0",
	"0       s                    s         0",
	"0       s                    s         0",
	"0                  s                   0",
	"0        s                   s         0",
	"0000000000000000000000000000000000000000",
};

sf::String start[HEIGHT_MAP] = {
	"0000000000000000000000000000000000000000",
	"0000000000000000000000000000000000000000",
	"0000000000000000000000000000000000000000",
	"000000                            000000",
	"00000                              00000",
	"0000                                0000",
	"0000                                0000",
	"0000                                0000",
	"0000                                0000",
	"0000                                0000",
	"0000                                0000",
	"0000                                0000",
	"0000                                    ",
	"0000                                    ",
	"0000                                    ",
	"0000                                    ",
	"0000                                    ",
	"0000                                    ",
	"0000                                0000",
	"0000                                0000",
	"0000                                0000",
	"0000                                0000",
	"0000                                0000",
	"0000                                0000",
	"0000                                0000",
	"00000                              00000",
	"000000                            000000",
	"0000000000000000000000000000000000000000",
	"0000000000000000000000000000000000000000",
	"0000000000000000000000000000000000000000",
};

sf::String A4Room[HEIGHT_MAP] = {
	"00000000000000000      00000000000000000",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"                                        ",
	"                                        ",
	"                                        ",
	"                                        ",
	"                                        ",
	"                                        ",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"00000000000000000      00000000000000000",
};