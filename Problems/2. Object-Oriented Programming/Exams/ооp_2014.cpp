#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
А) Да се дефинира структура ChessPosition, описваща коректна позиция на фигура върху шахматна дъска (координатите на позицията са от 'A' до 'H'
по едното измерение и от 1 до 8 по другото).
Да се дефинира абстрактен клас (или интерфейс) ChessPiece, описващ шахматна фигура със следните операции:
    • ChessPosition getPosition() – Връща позицията на фигурата на дъската;
    • [подходящ тип] allowedMoves() – Връща списък (колекция) с всички възможни позиции, до които дадена фигура може да достигне с един ход;
    • [булев тип] captures(ChessPosition pos) – Проверява дали фигурата "владее" позицията pos, подадена като параметър, т.е. дали позицията е
    в списъка с възможните ходове на фигурата. Булевият тип да бъде булевият тип в езика, който сте избрали (напр. bool на C++).
Б) Да се дефинират класовете Rook и Knight – наследници на ChessPiece, описващи съответно шахматните фигури топ и кон.
В) "Стабилна конфигурация" наричаме такава подредба на фигурите върху дъската, при която никоя фигура да не е върху позволен ход на друга фигура
(т.е. никои две фигури да не се "бият").
Да се дефинира функцията allMoves ([подходящ тип] pieces[, …]), която за списъка (колекцията) pieces, съдържащ произволен брой разнородни шахматни
фигури, отпечатва на конзолата всеки възможен ход на фигура от pieces такъв, че след изпълнението му списъкът с фигури да описва стабилна конфигурация.
Информацията за ходовете да съдържа типа на фигурата, старата позиция и новата позиция, например:
Rook A1 ‐> B1
Knight B3 ‐> A5
Забележка: Реализирайте всички конструктори и други операции, които смятате, че са необходими на съответните класове. 
*/

struct ChessPosition {
    char file;
    short rank;

    ChessPosition(char f, short r) : file(f), rank(r) {}

    // Копиращ конструктор
    ChessPosition(const ChessPosition& other) = default;

    bool isValid() const {
        return file >= 'A' && file <= 'H' && rank >= 1 && rank <= 8;
    }

    string toString() const {
        return string(1, file) + to_string(rank);
    }

    bool operator==(const ChessPosition& other) const {
        return file == other.file && rank == other.rank;
    }
};

class ChessPiece {
    public:
        virtual ChessPosition getPosition() const = 0;
        virtual vector<ChessPosition> allowedMoves() const = 0;
        virtual bool captures(const ChessPosition& pos) const {
            for (const auto& move : allowedMoves()) {
                if (move == pos) return true;
            }
            return false;
        }
        virtual string getType() const = 0;
        virtual void moveTo(const ChessPosition& newPos) = 0;
        virtual ChessPiece* clone() const = 0; // за копиране
        virtual ~ChessPiece() {}
};

class Knight : public ChessPiece {
    public:
        Knight(ChessPosition p) : pos(p) {}

        ChessPosition getPosition() const {
            return pos;
        }

        vector<ChessPosition> allowedMoves() const override {
            vector<ChessPosition> moves;
            int df[] = {1, 2, 2, 1, -1, -2, -2, -1};
            int dr[] = {2, 1, -1, -2, -2, -1, 1, 2};

            for (int i = 0; i < 8; ++i) {
                char f = pos.file + df[i];
                int r = pos.rank + dr[i];
                ChessPosition newPos(f, r);

                if (newPos.isValid()) {
                    moves.push_back(newPos);
                }
            }

            return moves;
        }

        string getType() const override {
            return "Knight";
        }

        void moveTo(const ChessPosition& newPos) override {
            pos = newPos;
        }

        ChessPiece* clone() const override {
            return new Knight(*this);
        }

    private:
        ChessPosition pos;
};

class Rook : public ChessPiece {
    public:
        Rook(ChessPosition p) : pos(p) {}

        ChessPosition getPosition() const {
            return pos;
        }

        vector<ChessPosition> allowedMoves() const override {
            vector<ChessPosition> moves;

            // Хоризонтално (по file)
            for (char f = 'A'; f <= 'H'; ++f) {
                if (f != pos.file)
                    moves.emplace_back(f, pos.rank);
            }

            // Вертикално (по rank)
            for (short r = 1; r <= 8; ++r) {
                if (r != pos.rank)
                    moves.emplace_back(pos.file, r);
            }

            return moves;
        }

        string getType() const override {
            return "Rook";
        }

        void moveTo(const ChessPosition& newPos) override {
            pos = newPos;
        }

        ChessPiece* clone() const override {
            return new Rook(*this);
        }

    private:
        ChessPosition pos;
};

bool isStable(const vector<ChessPiece*>& pieces) {
    for (size_t i = 0; i < pieces.size(); ++i) {
        for (size_t j = 0; j < pieces.size(); ++j) {
            if (i != j && pieces[i]->captures(pieces[j]->getPosition())) {
                return false;
            }
        }
    }
    return true;
}

void allMoves(const vector<ChessPiece*>& pieces) {
    for (size_t i = 0; i < pieces.size(); ++i) {
        ChessPiece* piece = pieces[i];
        ChessPosition original = piece->getPosition();

        for (const auto& move : piece->allowedMoves()) {
            // Клонираме всички фигури
            vector<ChessPiece*> copy;

            for (size_t j = 0; j < pieces.size(); ++j) {
                if (j == i) {
                    ChessPiece* moved = piece->clone();
                    moved->moveTo(move);
                    copy.push_back(moved);
                }
                else {
                    copy.push_back(pieces[j]->clone());
                }
            }

            if (isStable(copy)) {
                cout << piece->getType() << " " << original.toString() << " -> " << move.toString() << endl;
            }

            // Освобождаваме клонираните обекти
            for (ChessPiece* p : copy)
                delete p;
        }
    }
}


int main() {
    
    vector<ChessPiece*> pieces;

    pieces.push_back(new Rook(ChessPosition('A', 1)));
    pieces.push_back(new Knight(ChessPosition('B', 3)));
    pieces.push_back(new Knight(ChessPosition('D', 4)));

    cout << "Възможни стабилни ходове:\n";
    allMoves(pieces);

    // Освобождаваме основните фигури
    for (ChessPiece* p : pieces)
        delete p;

    return 0;
}