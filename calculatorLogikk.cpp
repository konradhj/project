#include "calculatorLogikk.h"

std::string message;
std::vector<std::string> operasjon;
std::string siffer; // midlertidig tall holder
std::vector<double> tall; // endelig tall  


void output(std::string nyOutput) {
    message += nyOutput;
    std::cout << message << std::endl; // TODO! endre til å skrive på vinduet
}


void operasjonstrykk(std::string nyOperasjon) {
    if (!siffer.empty()) {
        operasjon.push_back(nyOperasjon);
        tall.push_back(std::stod(siffer));
        siffer = "";
        output(nyOperasjon);
    } else {
        operasjon.back() = nyOperasjon;
        message.pop_back();
        message += nyOperasjon;
        output("");
    }
}

void lagTall(std::string nyttSiffer) {
    siffer += nyttSiffer;
}

void clear() {
    message = "";
    operasjon.clear();
    siffer = "";
    tall.clear();
    output("");
}

void clearEntry() {
    if (!siffer.empty()) {
        siffer.pop_back();
        message.pop_back();
        output("");
    }
}

void equals() {
    // 1) Prøv å legge inn siste tall om det finnes noe i siffer-bufferet
    if (!siffer.empty()) {
        try {
            tall.push_back(std::stod(siffer));
        } catch (...) {
            output("Ugyldig tall");
            message = "";
            operasjon.clear();
            siffer = "";
            tall.clear();
            return;
        }
        siffer.clear();
    }

    // 2) Sjekk at vi har nok tall
    if (tall.empty()) {
        message = "Ingen verdi";
        output("");
        message = "";
        operasjon.clear();
        siffer = "";
        tall.clear();
        return;
    }

    // 3) Hvis det er en ekstra operator
    if (operasjon.size() >= tall.size()) {
        message = "feil skrevet";
        output("");
        message = "";
        operasjon.clear();
        siffer = "";
        tall.clear();
        return;
    }

    // 4) Første pass: håndter * og /
    std::vector<double> tempTall;
    std::vector<std::string> tempOperasjon;

    tempTall.push_back(tall[0]);

    for (size_t i = 0; i < operasjon.size(); ++i) {
        std::string op = operasjon[i];
        double next = tall[i + 1];

        if (op == "*") {
            tempTall.back() *= next;
        }
        else if (op == "/") {
            if (next == 0.0) {
                output("NaN");
                message = "";
                operasjon.clear();
                siffer = "";
                tall.clear();
                return;
            }
            tempTall.back() /= next;
        }
        else {
            tempOperasjon.push_back(op);
            tempTall.push_back(next);
        }
    }

    // 5) Andre pass: håndter + og -
    double result = tempTall[0];
    for (size_t i = 0; i < tempOperasjon.size(); ++i) {
        if (tempOperasjon[i] == "+") {
            result += tempTall[i + 1];
        }
        else if (tempOperasjon[i] == "-") {
            result -= tempTall[i + 1];
        }
    }
    
    // skriv ut etc
    message = std::to_string(result);
    output("");
    // Clear uten å skrive ut
    message = "";
    operasjon.clear();
    siffer = "";
    tall.clear();

}

// endre fortegn
void changeSign() {
    if (!siffer.empty()) {
        message.erase(message.size() - siffer.size());
    }
    if (siffer[0] == '-') {
        // Har allerede '-', fjern det -> gjør tallet positivt
        siffer.erase(0, 1);
    } else {
        // Ikke '-', sett det inn -> gjør tallet negativt
        siffer.insert(0, "-");
    }
    message += siffer;

    output("");
}