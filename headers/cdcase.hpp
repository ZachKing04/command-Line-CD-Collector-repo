#include <iostream>
#include <vector>
#pragma once
using std::string;

class CD
{
    public:
        string Artist;
        string Title;
        int Year;
        string Country;
        bool Fav = false;


        CD(string artist, string title, int year, string country);
};

class CDCase
{
    public:
        std::vector<CD> Collection;
        std::vector<CD> Favorites;
        std::vector<CD> Wishlist;

        CDCase() {}
        

        void sortCD(string sortComparator, string vectorName);

        void addCD(string artist, string title, int year, string country);

        void removeCD(string artistInp, string albumInp);

        void displayCollection();

        void addtoFavorites(string artist, string album);

        void removeFavorite(string artist, string album);

        void addtoWishlist(string artist, string title, int year, string country);

        void removeWish(string artist, string title, bool moveToCollection);

        void displayWishlist();

        void saveToFile();

        void readFromFile();

};