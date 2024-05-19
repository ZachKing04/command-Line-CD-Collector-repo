#include <iostream>
#include <vector>
#include <algorithm>
using std::string;



class CD
{
    public:
        string Artist;
        string Title;
        int Year;
        string Country;
        bool Fav = false;


        CD(string artist, string title, int year, string country) //Constructor
            : Artist(artist), Title(title), Year(year), Country(country)
        {}
};
class CDCase
{
    public:
        std::vector<CD> Collection;
        std::vector<CD> Favorites;
        std::vector<CD> Wishlist;
        
        CDCase(){} //Default Constructor with no parameters

        static bool compareTitle(CD cd1, CD cd2) {return cd1.Artist < cd2.Artist;}
        //Used as the comparator for sorting the Collection vector

        void addCD(string artist, string title, int year, string country) 
        {
            CD newcd(artist, title, year, country);
            if (Collection.size() != 0)
            {
                for(auto cd : Collection) 
                {
                    if(newcd.Title == cd.Title && newcd.Artist == cd.Artist) 
                    {
                        std::cout << "This CD is already in your collection" << std::endl;
                        return;
                    }
                }
                    
                Collection.push_back(newcd);
                std::sort(Collection.begin(), Collection.end(), compareTitle);
                std::cout << newcd.Title << " by " << newcd.Artist << " added to your collection." << std::endl;
                    
                
            }else {
                Collection.push_back(newcd);
                std::sort(Collection.begin(), Collection.end(), compareTitle);
                std::cout << newcd.Title << " by " << newcd.Artist << " added to your collection." << std::endl;
            }
        }
        void removeCD(string artistInp, string albumInp) {
            bool found = false;
            for(int i = 0; i < Collection.size(); i++)
            {
                if(Collection.at(i).Artist == artistInp && Collection.at(i).Title == albumInp)
                {
                    Collection.erase(Collection.begin() + i);
                    found = true;
                }
            }

            if(found == true) 
            {
                std::cout << "Album has been removed." << std::endl;
            } else {
                std::cout << "Album not found." << std::endl;
            }

        }
        void displayCollection() { //TODO: Change this later to be more visually appealing
            for(auto cd : Collection) {
            std::cout << cd.Artist << " -- " << cd.Title << std::endl;
            }
        }

        void addtoFavorites(string artist, string album) {
            if(Favorites.size() != 5)
            {
                for(auto cd : Collection)
                {
                    if(cd.Artist == artist && cd.Title == album)
                    {
                        cd.Fav = true;
                        Favorites.push_back(cd);
                        std::cout << "Album added to favorites" << std::endl;
                        return;
                        
                    }
                }
                std::cout << "The album isn't in your collection." << std::endl;
            } else {
                std::cout << "You already have 5 favorite albums, album not added to favorites." << std::endl;
            }   
        }



        void removeFavorite(string artist, string album) {
            for(int i = 0; i < Favorites.size(); i++)
            {
                if(Favorites.at(i).Artist == artist && Favorites.at(i).Title == album)
                {
                    Favorites.at(i).Fav = false;
                    Favorites.erase(Favorites.begin() + i);
                    std::cout << "Album removed from favorites";
                    return;
                }
            }
            std::cout << "Album not found in favorites";
        }
        


        void addtoWishlist(string artist, string title, int year, string country) {
            
        }


        
        void removeWish(string artist, string title, bool moveToCollection) {}



        void displayWishlist() {}

        

        void saveToFile() {}


        
        void readFromFile() {}


            
    
};



int main() 
{
    
    CDCase collec;
    collec.addCD("The Smashing Pumpkins", "Siamese Dream", 1993, "US");
    collec.addCD("Bjork", "Vespertine", 2001, "Iceland");
    collec.addCD("The Cure", "Wish", 1991, "UK");
    collec.addCD("The Cure", "Disintegration", 1989, "UK");
    collec.removeCD("The Cure", "The Head on the Door");
    
    collec.displayCollection();



    
}

