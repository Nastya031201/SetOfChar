#include "SetOfChar.h"

int dialog(void) {
    system("cls");
    std::cout << "Enter action" << std::endl;
    std::cout << "1. Create an empty set of char." << std::endl;
    std::cout << "2. Create a set of char (power is known)" << std::endl;
    std::cout << "3. Create a set of char (string of symbols is known)" << std::endl;
    std::cout << "4. Show set of char" << std::endl;
    std::cout << "5. Union of two sets" << std::endl;
    std::cout << "6. Adding a new element to the set" << std::endl;
    std::cout << "7. Intersection of two sets" << std::endl;
    std::cout << "8. Subtraction of two sets" << std::endl;
    std::cout << "9. Element search in set" << std::endl;
    std::cout << "0. Exit" << std::endl;
    int a;
    getn(a);
    while (a >= 10 || a < 0)
    {
        getn(a);
    }
    return a;
}

const int M = 12;

int main() {
    // очищение массива указателей 
    // array - массив указателей на объекты, к которым мы будем обращаться в диалоге
    cs::SetOfChar* array[12];
    for (int i = 0; i < 12; i++)
    {
        array[i] = nullptr;
    }
    // 
    int k;
    while (k = dialog() != 0)
    {
        std::cout << " Write index of object, pls " << std::endl;
        int p;
        getn(p);
        while (p >= 11 || p < 0)
        {
            getn(p);
        }
        int (*functions[])(cs::SetOfChar*&, cs::SetOfChar**) = { dialogconstructor0, dialogconstructor1, dialogconstructor2, dialoginput, dialogoutput, dialogsetUnion, dialogadd, dialogintersection, dialogdiffer, dialogcontains, dialogmakeSet };

    }
}



int dialogconstructor0(cs::SetOfChar*& t, cs::SetOfChar** q) {
    cs::SetOfChar a;
    t = &a;
    //t = new cs::SetOfChar;
}

int dialogconstructor1(cs::SetOfChar*& t, cs::SetOfChar** q) {
    std::cout << " write power" << std::endl;
    int N;
    getn(N);
    try
    {
        cs::SetOfChar a(N);
        t = &a;
    }
    catch (const std::exception&)
    {
        return 0;
    }
}

int dialogconstructor2(cs::SetOfChar*& t, cs::SetOfChar** q) {
    std::cout << " write string of symbols" << std::endl;
    char str[100];
    std::cin.getline(str, 99);
    cs::SetOfChar a(str);
    t = &a;

}

int dialoginput(cs::SetOfChar*& t, cs::SetOfChar** q) {
    cs::SetOfChar a;
    cs::input(std::cin, a);
    t = &a;
}

int dialogoutput(cs::SetOfChar*& t, cs::SetOfChar** q) {
    if (t != nullptr)
    {
        cs::output(std::cout, *t);
    }
    else
    {
        std::cout << " error " << std::endl;
    }

}

int dialogsetUnion(cs::SetOfChar*& t, cs::SetOfChar** q) {
    if (t != nullptr)
    {
        std::cout << " Select the second term " << std::endl;
        int r;
        getn(r);
        if (r >= 0 && r < 12)
        {
            if (q[r] != nullptr) {
                t->setUnion(*t, *q[r]);
            }
            else {
                cs::SetOfChar a;
                q[r] = &a;
                t->setUnion(*t, *q[r]);
            }
        }
        else {
            std::cout << " error " << std::endl;
            return 0;
        }
    }
    else
    {
        std::cout << " error " << std::endl;
    }
}

int dialogadd(cs::SetOfChar*& t, cs::SetOfChar** q) {
    if (t != nullptr)
    {
        char c;
        std::cin.get(c);
        try
        {
            t->add(c);
        }
        catch (const std::exception& exception)
        {
            std::cout << exception.what() << std::endl;
            return 0;
        }
    }
    else
    {
        std::cout << " error " << std::endl;
    }
}

int dialogintersection(cs::SetOfChar*& t, cs::SetOfChar** q) {
    if (t != nullptr)
    {
        char d[100];
        std::cout << " Write string, pls" << std::endl;
        std::cin.getline(d, 100);
        cs::SetOfChar f(d);
        t->intersection(f, *t);
    }
    else
    {
        std::cout << " error " << std::endl;
    }
}

int dialogdiffer(cs::SetOfChar*& t, cs::SetOfChar** q) {
    if (t != nullptr)
    {
        char h[100];
        std::cout << " Write string, pls" << std::endl;
        std::cin.getline(h, 100);
        cs::SetOfChar y(h);
        t->differ(y, *t);
    }
    else
    {
        std::cout << " error " << std::endl;
    }
}

int dialogcontains(cs::SetOfChar*& t, cs::SetOfChar** q) {
    if (t != nullptr)
    {
        char s;
        std::cout << " Write a symbol, pls" << std::endl;
        std::cin.get(s);
        bool p;
        p = t->contains(s);
        std::cout << p << std::endl;
    }
    else
    {
        std::cout << " error " << std::endl;
    }
}

int dialogmakeSet(cs::SetOfChar*& t, cs::SetOfChar** q) {
    if (t != nullptr)
    {
        char x[100];
        std::cout << " Write a string, pls" << std::endl;
        std::cin.getline(x, 100);
        t->makeSet(x);
    }
    else
    {
        std::cout << " error " << std::endl;
    }
}
