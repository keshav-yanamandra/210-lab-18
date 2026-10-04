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

        // print reviews and average
        void print() {
            cout << "Movie Title: " << title << endl;

            Review *current = head;
            double total = 0;
            int count = 0;

            while (current) {
                count++;
                cout << "  > Review #" << count << ": " << current->rating << ": " << current->comment << endl;
                total = total + current->rating;
                current = current->next;
            }

            if (count > 0) {
                cout << "  > Average: " << total / count << endl;
            }

            cout << endl;
        }
};

int main() {

    Movie movie1("Test Movie");
    movie1.addReview(4.8, "Good movie.");
    movie1.addReview(3.8, "OK.");
    movie1.addReview(4.2, "I liked it.");

    movie1.print();


    return 0;
}

