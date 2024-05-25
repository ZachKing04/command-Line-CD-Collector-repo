#include <iostream>
#include <memory>
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
        std::vector<std::shared_ptr<CD>> Collection;
        std::vector<std::shared_ptr<CD>> Favorites;
        std::vector<std::shared_ptr<CD>> Wishlist;

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