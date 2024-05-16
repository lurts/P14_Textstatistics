//
// Created by larse on 2023-12-11.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include "textstatistik.h"

void toLower(std::string& text) {
    for (char& c : text) {
        if (std::isalpha(c)) {
            // Konvertiere den Buchstaben in Kleinbuchstaben
            c = std::tolower(c);
        }
    }
}

bool isNotAlpha(char c) {
    return !isalpha(c);
}

std::vector<std::string> readFile(std::string path) {
    //std::string content;

    std::vector<std::string> words;
    std::string word;

    std::ifstream file(path);

    if (!file.is_open()) {
        //Falls Datei nicht existiert leeren Vektor zurückgeben
        return words;
    }

    while (file >> word) {
        std::string::iterator  it = std::remove_if(word.begin(),word.end(),isNotAlpha);
        word.erase(it, word.end());
        std::transform(word.begin(), word.end(), word.begin(), tolower);

        words.push_back(word);
    }

    file.close();
    return words;
}


// Funktion zur Berechnung der Buchstaben-Häufigkeit
std::map<char, int> letterFreq(std::vector<std::string>& words) {
    // Initialisierung einer leeren unordered_map zur Speicherung der Buchstaben-Häufigkeit
    std::map<char, int> frequencyMap;


    // Iteriere durch jeden Buchstaben im Text
    for (std::string word : words)
    {
        for (char c : word)
        {
            frequencyMap[c]++;
        }
    }

    // Gib die fertige Buchstaben-Häufigkeitsmap zurück
    return frequencyMap;
}

// Funktion zur Bestimmung der Häufigkeit der Wörter im Text
std::set<std::string> wordFreq(std::vector<std::string>& words, unsigned int n) {
    // Initialisierung einer leeren unordered_map zur Speicherung der Wort-Häufigkeit
    std::set<std::string> wordSet;

    // Schleife, die die Funktion nextWord aufruft, bis das Ende des Textes erreicht ist
    for (std::string word : words)
    {
        if (word.length() == n) {
            // Inkrementiere die Häufigkeit des Worts in der Map
            wordSet.insert(word);
        }
    }

    // Gib die fertige Wort-Häufigkeitsmap zurück
    return wordSet;
}

// Funktion, die eine Tabelle mit den Statistiken ausgibt
void printStatistic(std::string& path, unsigned int begin, unsigned int end) {
    std::vector<std::string> words = readFile(path);

    std::map<char, int> charCount = letterFreq(words);


    std::cout << "*** Häufigkeit der Buchstaben ***\n";

    for (auto p : charCount) {
        std::cout << std::setw(15) << p.first << "\t\t" << std::setw(5) << p.second << "\n";
    }
    std::cout << "\n\n*** Häufigkeit der Wörter ***\n";

    for (int i = begin; i <= end; i++)
    {
        std::cout << std::setw(15) << i << "\t\t" << std::setw(5) << wordFreq(words, i).size() << "\n";
    }

    //Benutzereingabe
    int n;
    std::cout << "Wörter mit n Buchstaben anzeigen.\nn: ";
    std::cin >> n;

    for (std::string word : wordFreq(words, n))
    {
        std::cout << word << ", ";
    }
}