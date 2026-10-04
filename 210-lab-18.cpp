// Keshav Yanamandra
// COMSC-210-5293, Fall 2026
// Lab 18

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MIN = 10;
const int MAX = 50;
const int RANGE = MAX - MIN + 1;
const int MOVIE_COUNT = 4;
const int REVIEWS_PER_MOVIE = 3;


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

        // copy constructor 
        Movie(const Movie &other) {
            title = other.title;
            head = nullptr;

            Review *current = other.head;
            Review *last = nullptr;

            while (current) {
                Review *newnode = new Review;

                newnode->rating = current->rating;
                newnode->comment = current->comment;
                newnode->next = nullptr;

                if (head == nullptr) {
                    head = newnode;
                }
                else {
                    last->next = newnode;
                }

                last = newnode;
                current = current->next;
            }
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

        // copy assignment operator
        Movie& operator=(const Movie &other) {

            if (this != &other) {

                // delete old reviews
                Review *current = head;

                while (current != nullptr) {
                    head = current->next;
                    delete current;
                    current = head;
                }

                head = nullptr;

                // copy the title and reviews
                title = other.title;
                current = other.head;
                Review *last = nullptr;

                while (current != nullptr) {

                    Review *newnode = new Review;

                    newnode->rating = current->rating;
                    newnode->comment = current->comment;
                    newnode->next = nullptr;

                    if (head == nullptr) {
                        head = newnode;
                    }
                    else {
                        last->next = newnode;
                    }

                    last = newnode;
                    current = current->next;
                }
            }

            return *this;
        }

        //destructor
        ~Movie() {
            Review *current = head;

            while (current) {
                head = current->next;
                delete current;
                current = head;
            }

            head = nullptr;
        }
};

int main() {

    srand(time(0));
    cout << fixed << setprecision(1);

    Movie movies[MOVIE_COUNT] = {
        Movie("Lord of the Rings"),
        Movie("The Godfather"),
        Movie("Star Wars"),
        Movie("Jurassic Park")
    };

    ifstream fin("input.txt");
    string comment;
    int i = 0;
    int r = 0;

    if (fin.good()) {

        while (getline(fin, comment)) {
            int randomRating = (rand() % RANGE) + MIN;
            double rating = randomRating / 10.0;
            movies[i].addReview(rating, comment);
            r++;

            if (r == REVIEWS_PER_MOVIE) {
                i++;
                r = 0;
            }
        }

        fin.close();
    }
    else {
        cout << "File not found." << endl;
        return 1;
    }

    for (int j = 0; j < MOVIE_COUNT; j++) {
        movies[j].print();
    }

    // testing copy constructor
    Movie copyConstTest = movies[0];
    cout << "TESTING COPY" << endl;
    copyConstTest.print();


    copyConstTest.addReview(5.0, "Extra test review.");

    cout << "COPY:" << endl;
    copyConstTest.print();

    cout << "ORIGINAL:" << endl;
    movies[0].print();


    return 0;
}
