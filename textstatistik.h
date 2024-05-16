//
// Created by larse on 2023-12-11.
//

#ifndef P2A6_TEXTSTATISTIK_H
#define P2A6_TEXTSTATISTIK_H

#include <string>
#include <map>
#include <vector>

//funktion um text in kleinbuchstaben zu konvertieren
void toLower(std::string& text);

//text aus datei einlesen
std::vector<std::string> readFile(std::string path);

//pro aufruf das nächste wort zurückgeben
//std::string nextWord(std::string& text);

//häufigkeit der buchstaben bestimmen
std::map<char, int> letterFreq(std::vector<std::string>& text);

//häufigkeit der wörter bestimmen
std::map<std::string, int> wordFreq(std::string& text);

//tabelle mit den statistiken ausgeben
void printStatistic(std::string& path, unsigned int, unsigned int);

#endif //P2A6_TEXTSTATISTIK_H
