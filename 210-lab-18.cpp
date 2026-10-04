// Keshav Yanamandra
// COMSC-210-5293, Fall 2026
// Lab 18

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Review {
    double rating;
    string comment;
    Review *next;
};

class Movie {
    private:
        string title;
        Review *head;

    public:
        // default constructor
        Movie() {
            title = "";
            head = nullptr;
        }

        // constructor with title
        Movie(string t) {
            title = t;
            head = nullptr;
        }

        // add review to head
        void addReview(double r, string c) {
            Review *newnode = new Review;

            newnode->rating = r;
            newnode->comment = c;
            newnode->next = head;

            head = newnode;
        }
};

int main() {

    return 0;
}

