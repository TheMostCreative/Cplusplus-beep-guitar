// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

		int main(){
			std::vector<int> chords_v;
			std::vector<int> strings_v;
			std::vector<int> duration_v;
			int strings, chord, duration;
			char b;
			std::fstream myfile("D:/Programming/ConsoleApplication10/lolly.txt");
			if (!myfile.is_open()){
				std::cout << "try again" << std::endl;
				return 0;
			}
			else{
				while (!myfile.eof()){
					myfile >> strings >> b >> chord >> b >> duration;
					std::cout << strings << std::endl;
					std::cout << chord << std::endl;
					std::cout << duration << std::endl;
					chords_v.push_back(chord);
					strings_v.push_back(strings);
					duration_v.push_back(duration);
				}
			}
			myfile.close();
			int octava = 3;
			while (true) {
				for (int i = 0; i < strings_v.size(); ++i){
					float n = 0;
					switch (strings_v[i]){
					case 1:
						n = 329.63 * octava;
						break;
					case 2:
						n = 246.94 * octava;
					case 3:
						n = 196.00 * octava;
					case 4:
						n = 146.83 * octava;
					case 5:
						n = 110.00 * octava;
					case 6:
						n = 82.41 * octava;
					}
					for (int j = 0; j < chords_v[i]; ++j){
						n *= pow(2, 1. / 12);
					}
					Beep(n, duration_v[i]);
				}
			}
			return 0;
		}