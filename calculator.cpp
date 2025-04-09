#include "calculator.h"


void createWindow() {

    //Initialiserer posisjonen til vinduet
    int windowPositionX = 460;
    int windowPostitionY = 110;
    int windowWidth = 560;
    int windowHeight = 720;
    std::string windowTitle = "Kalkulator";
    TDT4102::AnimationWindow window(windowPositionX, windowPostitionY, windowWidth, windowHeight, windowTitle);

    //Legger til knapper
    TDT4102::Button button1 = addButton({0, 540}, "1");
    TDT4102::Button button2 = addButton({140, 540}, "2");
    TDT4102::Button button3 = addButton({280, 540}, "3");
    TDT4102::Button button4 = addButton({0, 450}, "4");
    TDT4102::Button button5 = addButton({140, 450}, "5");
    TDT4102::Button button6 = addButton({280, 450}, "6");
    TDT4102::Button button7 = addButton({0, 360}, "7");
    TDT4102::Button button8 = addButton({140, 360}, "8");
    TDT4102::Button button9 = addButton({280, 360}, "9");
    TDT4102::Button button0 = addButton({140, 630}, "0");

    TDT4102::Button buttonEquals = addButton({420, 630}, "=");
    TDT4102::Button buttonPlus = addButton({420, 540}, "+");
    TDT4102::Button buttonMinus = addButton({420, 450}, "-");
    TDT4102::Button buttonMultiply = addButton({420, 360}, "×");
    TDT4102::Button buttonDivide = addButton({420, 270}, "÷");

    TDT4102::Button buttonC = addButton({0, 270}, "C");
    TDT4102::Button buttonCE = addButton({140, 270}, "CE");
    TDT4102::Button buttonSign = addButton({280, 270}, "+/-");
    TDT4102::Button buttonComma = addButton({280, 630}, ",");
    TDT4102::Button buttonNothing = addButton({0, 630}, "");

    //initialiserer knappene med callbackfunksjon og legger dem til i vinduet
    window.add(button1);
    button1.setCallback(callback1);

    window.add(button2);
    button2.setCallback(callback2);

    window.add(button3);
    button3.setCallback(callback3);

    window.add(button4);
    button4.setCallback(callback4);

    window.add(button5);
    button5.setCallback(callback5);
    window.add(button6);
    button6.setCallback(callback6);

    window.add(button7);
    button7.setCallback(callback7);
    window.add(button8);
    button8.setCallback(callback8);
    window.add(button9);
    button9.setCallback(callback9); 
    window.add(button0);
    button0.setCallback(callback0);

    window.add(buttonEquals);
    buttonEquals.setCallback(callbackEquals);
    window.add(buttonPlus);
    buttonPlus.setCallback(callbackPlus);
    window.add(buttonMinus);
    buttonMinus.setCallback(callbackMinus);
    window.add(buttonMultiply);
    buttonMultiply.setCallback(callbackMultiply);
    window.add(buttonDivide);
    buttonDivide.setCallback(callbackDivide);

    window.add(buttonC);
    buttonC.setCallback(callbackC);
    window.add(buttonCE);
    buttonCE.setCallback(callbackCE);
    window.add(buttonSign);
    buttonSign.setCallback(callbackSign);
    window.add(buttonComma);
    buttonComma.setCallback(callbackComma);
    window.add(buttonNothing);

    window.wait_for_close();


}

TDT4102::Button addButton(const TDT4102::Point& buttonPosition, const std::string& buttonLabel) {
    const unsigned int buttonWidth = 140;
    const unsigned int buttonHeight = 90;
    TDT4102::Button button {buttonPosition, buttonWidth, buttonHeight, buttonLabel};

    return button;
}

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