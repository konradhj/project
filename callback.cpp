#include "callback.h"
#include <iostream>

//Callback funksjoner
int callback1() {
    output("1");
    lagTall("1");
        return 1;
}

int callback2() {
    output("2");
    lagTall("2");
        return 2;
    }

int callback3() {
    output("3");
    lagTall("3");
        return 3;
    }

int callback4() {
    output("4");
    lagTall("4");
        return 4;
    }

int callback5() {
    output("5");
    lagTall("5");
        return 5;
    }

int callback6() {
    output("6");
    lagTall("6");
        return 6;
    }

int callback7() {
    output("7");
    lagTall("7");
        return 7;
    }

int callback8() {
    output("8");
    lagTall("8");
        return 8;
    }

int callback9() {
    output("9");
    lagTall("9");
        return 9;
    }

int callback0() {
    output("0");
    lagTall("0");
        return 0;
    }
void callbackComma() {
    output(".");
    lagTall(".");
}

void callbackPlus() {
    operasjonstrykk("+");
}
void callbackMinus() {
    operasjonstrykk("-");
}
void callbackMultiply() {
    operasjonstrykk("*");
}
void callbackDivide() {
    operasjonstrykk("/");
}

void callbackC() {
    clear();
}

void callbackCE() {
    clearEntry();
}

void callbackEquals() {
    equals();
}

void callbackSign() {
    changeSign();
}