#ifndef THEATRE_H
#define THEATRE_H

#include <iostream>
#define SIZE 120;
using namespace std;

class Theatre {
    public:
        enum Rating {U,R,A};
    private:
        int id;
        string name;
        string director;
        Rating rating;
        int runtime;
        string casts[2];
        int totSeats;
        
    public:
        Theatre();
        Theatre(string name, string dir, Rating r, int runtime, string *cast, int seats);
        ~Theatre();

        void bookTicket(string, int);
        void addMovie();
        void getMovie(int id);

        int getId() const { return id; }
        void setId(int id_) { id = id_; }

        string getName() const { return name; }
        void setName(const string &name_) { name = name_; }

        string getDirector() const { return director; }
        void setDirector(const string &director_) { director = director_; }

        Rating getRating() const { return rating; }
        void setRating(const Rating &rating_) { rating = rating_; }

        int getRuntime() const { return runtime; }
        void setRuntime(int runtime_) { runtime = runtime_; }

        string* getCasts()  { return casts; }
        void setCasts( string *casts_) { 
            this->casts[0] = casts_[0];
            this->casts[1] = casts_[1];
        }

        int getTotSeats() const { return totSeats; }
        void setTotSeats(int totSeats_) { totSeats = totSeats_; }

        friend ostream& operator <<(ostream& os, Theatre& t) {
            os<<"\nMovie Id: "<<t.getId();
            os<<"\nMovie Name: "<<t.getName();
            os<<"\nMovie director: "<<t.getDirector();
            os<<"\nMovie Casts: ";
            string *str = t.getCasts();
            for (int i = 0; i < 2; i++)
                os<<str[i]<<", ";
            
            return os;
        }
};

#endif // THEATRE_H
