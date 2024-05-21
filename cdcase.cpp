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

        static bool compareArtist(CD cd1, CD cd2) {return cd1.Artist < cd2.Artist;}  //Used as the default comparator for sorting the Collection vector

	
    
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
                std::sort(Collection.begin(), Collection.end(), compareArtist);
                std::cout << newcd.Title << " by " << newcd.Artist << " added to your collection" << std::endl;
                    
                
            }else {
                Collection.push_back(newcd);
                std::sort(Collection.begin(), Collection.end(), compareArtist);
                std::cout << newcd.Title << " by " << newcd.Artist << " added to your collection." << std::endl;
            }
        }
        void removeCD(string artistInp, string albumInp) 
        {
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
        void displayCollection() 
        {   //TODO: Change this later to be more visually appealing
            //      Artist: 30 spaces  Title: 40 Spaces   Year: 10  Country(2-letter code): 8    Fav: 5 
            //
            std::cout << "+-------------------------------+----------------------------------------+----------+---------+-----+" << std::endl;                                         
            std::cout << "|             Artist            |                 Title                  |   Year   | Country | Fav |" << std::endl;
            std::cout << "+-------------------------------+----------------------------------------+----------+---------+-----+" << std::endl; 
            //            | Cinema Staff                  | Blue, Under the Imagination            |   2010   |   JP    |  *  |   separators and bottom borders part of loop
            //            +-------------------------------+----------------------------------------+----------+---------+-----+    
            for(auto cd : Collection)
            {
                string mainStr = "| " + cd.Artist;
                for(int i = 0; i < 31-(cd.Artist.length() + 1); i++)
                {
                    mainStr += " ";
                }
                mainStr += "| " + cd.Title;
                for(int i = 0; i < 40-(cd.Title.length() + 1); i++)
                {
                    mainStr += " ";
                }
                mainStr += "|   " + std::to_string(cd.Year) + "   ";
                mainStr += "|   " + cd.Country + "    ";
                
                
                if(cd.Fav == true)
                {
                    mainStr += "|  *  |";   
                } else {
                    mainStr += "|     |";
                }
                std::cout << mainStr << "\n" << "+-------------------------------+----------------------------------------+----------+---------+-----+" << std::endl;






            }
        }

        void addtoFavorites(string artist, string album) 
        {
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



        void removeFavorite(string artist, string album) 
        {
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
        


        void addtoWishlist(string artist, string title, int year, string country) 
        {
        	    CD newcd = CD(artist, title, year, country);
                bool collec_found = false;
                bool wishl_found = false;
                for(auto cd : Collection)
                {
                    if(newcd.Artist == cd.Artist && newcd.Title == cd.Title)
                    {
                        collec_found = true;
                    }
                }
                for(auto cd : Wishlist)
                {
                    if(newcd.Artist == cd.Artist && newcd.Title == cd.Title)
                    {
                        wishl_found = true;
                    }
                }
                if(collec_found == true)
                {
                    std::cout << "You already own this album" << std::endl;
                } else if(wishl_found == true) {
                    std::cout << "Album already in your wishlist" << std::endl;
                } else {
                    Wishlist.push_back(newcd);
                    std::sort(Wishlist.begin(), Wishlist.end(), compareArtist);
                    std::cout << newcd.Title << " by " << newcd.Artist << " added to your wishlist" << std::endl;
                    
                }
                 
        }


        
        void removeWish(string artist, string title, bool moveToCollection) 
        {   
            bool cd_found = false;
            if(moveToCollection == false)
            {
                for(int i = 0; i < Wishlist.size(); i++){
                    if(Wishlist.at(i).Artist == artist && Wishlist.at(i).Title == title){
                        Wishlist.erase(Wishlist.begin() + i);
                        std::cout << "Album removed from withlist" << std::endl;
                        cd_found = true;
                    }
                }
            } else {
                for(int i = 0; i < Wishlist.size(); i++){
                    if(Wishlist.at(i).Artist == artist && Wishlist.at(i).Title == title){
                        Collection.push_back(Wishlist.at(i));
                        std::sort(Collection.begin(), Collection.end(), compareArtist);
                        Wishlist.erase(Wishlist.begin() + i);
                        std::cout << "Album moved to collections" << std::endl;
                        cd_found = true;
                    }
                }
            }
            if(cd_found == false)
            {
                std::cout << "Album not found in your wishlist" << std::endl;
            }
        }



        void displayWishlist() 
        {  // TODO: Fix the ui to make it look more visually appealing and informative
            std::cout << "+-------------------------------+----------------------------------------+----------+---------+-----+" << std::endl;                                         
            std::cout << "|             Artist            |                 Title                  |   Year   | Country | Fav |" << std::endl;
            std::cout << "+-------------------------------+----------------------------------------+----------+---------+-----+" << std::endl; 
            //            | The Cure                      | Disintegration                         |   1989   |   US    |  *  |   separators and bottom borders part of loop
            //            +-------------------------------+----------------------------------------+----------+---------+-----+    
            for(auto cd : Collection)
            {
                string mainStr = "| " + cd.Artist;
                for(int i = 0; i < 31-(cd.Artist.length() + 1); i++)
                {
                    mainStr += " ";
                }
                mainStr += "| " + cd.Title;
                for(int i = 0; i < 40-(cd.Title.length() + 1); i++)
                {
                    mainStr += " ";
                }
                mainStr += "|   " + std::to_string(cd.Year) + "   ";
                mainStr += "|   " + cd.Country + "    ";
                
                
                std::cout << mainStr << "\n" << "+-------------------------------+----------------------------------------+----------+---------+-----+" << std::endl;
            }  
        }

        

        void saveToFile() 
        {

        }


        
        void readFromFile() 
        {

        }


            
    
};



int main() 
{
    
    CDCase collec;
    collec.addCD("The Smashing Pumpkins", "Siamese Dream", 1993, "US");
    collec.addCD("Bjork", "Vespertine", 2001, "IC");
    collec.addCD("The Cure", "Wish", 1991, "UK");
    collec.addCD("The Cure", "Disintegration", 1989, "UK");
    // collec.removeCD("The Cure", "The Head on the Door");
    
    collec.displayCollection();

    



    
}

