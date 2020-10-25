#include "SetOfChar.h"
#include <iostream>


cs::SetOfChar::SetOfChar(int power) {
    if (power < 0) {
        std::cout << "Power of Set couldn`t be negative!" << std::endl;
        throw "error: negative power";
    }
    else if (power > MAX_SET_POWER) {
        std::cout << "Power value = " << power << " exceeds the admissible value!" << std::endl;
        std::cout << "Max value of Set Power is: " << MAX_SET_POWER << std::endl;
        throw "error: exceeding max power value";
    }
    else {
        currentPower = power;
        int a = char(' ');
        for (int i = 0; i < currentPower; i++)
            set[i] = char(a + i);
    }
}


cs::SetOfChar::SetOfChar(const char* symbolString) {
    currentPower = strlen(symbolString);
    char* str = new char[currentPower];
    strncpy(str, symbolString, currentPower);
    std::sort(str, str + currentPower);
    str[currentPower] = '\0';

    makeSet(str);
}


std::istream& cs::input(std::istream& p, cs::SetOfChar& s) {
    char str[s.MAX_SET_POWER];
    p.getline(str, s.getMaxPower());
    p.getline(str, s.getMaxPower());

    s.currentPower = strlen(str);
    std::sort(str, str + s.currentPower);
    str[s.currentPower] = '\0';

    s.makeSet(str);

    return p;
}


std::ostream& cs::output(std::ostream& p, const cs::SetOfChar& s) {
    if (s.currentPower > 0) {
        std::cout << "{";
        int i;
        for (i = 0; i < s.currentPower - 1; i++)
            std::cout << "'" << s.set[i] << "', ";
        std::cout << "'" << s.set[i] << "'}";
    }
    else {
        std::cout << "Set is empty";
    }

    return p;
}


bool cs::SetOfChar::contains(char item) const {
    for (int i = 0; i < currentPower; i++) {
        if (set[i] == item)
            return true;
    }

    return false;
}


void cs::SetOfChar::makeSet(char* str) {
    int j = 0;
    int i = 0;
    while (i < currentPower) {
        if (str[i] != str[i + 1]) {
            set[j++] = str[i];
        }
        i++;
    }
    set[currentPower] = '\0';

    currentPower = j;
}


cs::SetOfChar cs::SetOfChar::setUnion(const cs::SetOfChar& set1, const cs::SetOfChar& set2) {
    SetOfChar result;

    strcpy(result.set, set1.set);
    result.currentPower = set1.currentPower;

    for (int i = 0; i < set2.currentPower; i++)
        result.add(set2.set[i]);

    return result;
}


cs::SetOfChar cs::SetOfChar::add(const char item) {
    if (currentPower + 1 > MAX_SET_POWER) {
        throw "Set is full";
    }
    else if (contains(item)) {
        std::cout << "Set is already contains this element" << std::endl;
        return;
    }
    else {
        set[currentPower] = item;
        currentPower++;
    }
    return;
}


void cs::SetOfChar::addWithoutCheckingContaining(const char item) {
    if (currentPower + 1 > MAX_SET_POWER) {
        std::cout << "Set is full" << std::endl;
        return;
    }
    else {
        set[currentPower] = item;
        currentPower++;
    }

    return;
}


cs::SetOfChar cs::SetOfChar::intersection(const cs::SetOfChar& set1, const cs::SetOfChar& set2) {
    SetOfChar result;

    if (set1.currentPower < set2.currentPower) {
        for (int i = 0; i < set1.currentPower; i++) {
            if (set2.contains(set1.set[i]))
                result.addWithoutCheckingContaining(set1.set[i]);
        }
    }
    else {
        for (int i = 0; i < set2.currentPower; i++) {
            if (set1.contains(set2.set[i]))
                result.addWithoutCheckingContaining(set2.set[i]);
        }
    }

    return result;
}


cs::SetOfChar cs::SetOfChar::differ(const cs::SetOfChar& set1, const cs::SetOfChar& set2) {
    SetOfChar result;
    result.currentPower = 0;
    for (int i = 0; i < set1.currentPower; i++)
        if (!set2.contains(set1.set[i])) {
            result.add(set1.set[i]);
        }
    return result;
}
