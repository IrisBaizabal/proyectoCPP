#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Reportable {
    public:
        virtual string getReportType() const = 0;
        virtual ~Reportable() {}
};

class Episode{
    private:
        string title;
        int season;
        vector<int> ratings;
    public:
        Episode(string title, int season);

        string getTitle() const;
        int getSeason() const;
        int getRatingCount() const;

        void print(ostream& out) const;

};

class Video{
    protected:
    int id;
    string name;
    int length;
    string genre;
    vector<int> ratings;

    public:
    Video(int id, string name, int length, string genre);
    virtual ~Video(){}

    int getId() const;
    string getName() const;
    int getLength() const;
    string getGenre() const;
    
    void addRating(int stars);
    double getAverageRating() const;
    int getRatingCount() const;

    virtual string getType() const = 0;
    virtual void print(ostream& out) const = 0;

    friend ostream& operator<<(ostream& out, const Video& video);


};

class Movie : public Video{
    public:
    Movie(int id, string name, int length, string genre);
    
    string getType() const override;
    void print(ostream& out) const override;

};

class Series : public Video, public Reportable {
    private:
    vector<Episode> episodes;

    public:
    Series(int id, string name, int length, string genre);
    
    void addEpisode(const Episode& e);
    const vector<Episode>& getEpisodes() const;

    string getType() const override;
    void print(ostream& out) const override;

    string getReportType() const override;

};



#endif