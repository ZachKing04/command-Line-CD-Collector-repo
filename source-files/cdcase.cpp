
#include <algorithm>
#include "../headers/cdcase.hpp"




CD::CD(string artist, string title, int year, string country) //Constructor
    : Artist(artist), Title(title), Year(year), Country(country)
{}

 

//bool CDCase::compareArtist(CD cd1, CD cd2) {return cd1.Artist < cd2.Artist;}  Was used as the default comparator for sorting the Collection vector

void CDCase::sortCD(string sortComparator, string vectorName)  //sorting will now be done in programLoop instead
{
    if(vectorName == "Collection")
    {
        if(sortComparator == "Artist")
        {
            std::sort(Collection.begin(), Collection.end(), [] (CD leftCD, CD rightCD) {return leftCD.Artist < rightCD.Artist;});
        } else if (sortComparator == "Title") {
            std::sort(Collection.begin(), Collection.end(), [] (CD leftCD, CD rightCD) {return leftCD.Title < rightCD.Title;});
        } else if (sortComparator == "Year") {
            std::sort(Collection.begin(), Collection.end(), [] (CD leftCD, CD rightCD) {return leftCD.Year < rightCD.Year;});
        } else {
            std::sort(Collection.begin(), Collection.end(), [] (CD leftCD, CD rightCD) {return leftCD.Country < rightCD.Country;});
        }
    } else {
        if(sortComparator == "Artist")
        {
            std::sort(Wishlist.begin(), Wishlist.end(), [] (CD leftCD, CD rightCD) {return leftCD.Artist < rightCD.Artist;});
        } else if (sortComparator == "Title") {
            std::sort(Wishlist.begin(), Wishlist.end(), [] (CD leftCD, CD rightCD) {return leftCD.Title < rightCD.Title;});
        } else if (sortComparator == "Year") {
            std::sort(Wishlist.begin(), Wishlist.end(), [] (CD leftCD, CD rightCD) {return leftCD.Year < rightCD.Year;});
        } else {
            std::sort(Wishlist.begin(), Wishlist.end(), [] (CD leftCD, CD rightCD) {return leftCD.Country < rightCD.Country;});
        }
    }
}

	
void CDCase::addCD(string artist, string title, int year, string country) // sort after
{
    CD newcd(artist, title, year, country);
    if (Collection.size() != 0)
    {
        for(auto &cd : Collection) 
        {
            if(newcd.Title == cd.Title && newcd.Artist == cd.Artist) 
            {
                std::cout << "This CD is already in your collection" << std::endl;
                return;
            }
        }
            
        Collection.push_back(newcd);
        std::cout << newcd.Title << " by " << newcd.Artist << " added to your collection" << std::endl;
            
        
    }else {
        Collection.push_back(newcd);
        std::cout << newcd.Title << " by " << newcd.Artist << " added to your collection." << std::endl;
    }
}

void CDCase::removeCD(string artistInp, string albumInp) 
{
    for(int i = 0; i < Collection.size(); i++)
    {
        if(Collection.at(i).Artist == artistInp && Collection.at(i).Title == albumInp)
        {
            if(Collection.at(i).Fav)
            {
                for(int i = 0; i < Favorites.size(); i++)
                {
                    Favorites.erase(Favorites.begin() + i);
                }
            }
            Collection.erase(Collection.begin() + i);
            std::cout << "Album has been removed." << std::endl;
            return;
        }
    }
    std::cout << "Album not found." << std::endl;
}
/*
void CDCase::removeCD(string artistInp, string albumInp) 
{
    for(auto &cd : Collection)
    {
        if(cd.Artist == artistInp && cd.Title == albumInp)
        {
            if(cd.Fav)
            {
                //Favorites.erase(std::remove(Favorites.begin(), Favorites.end(), cd), Favorites.end());
            }
            Collection.erase(std::remove(Collection.begin(), Collection.end(), cd), Collection.end());
            std::cout << "Album has been removed" << std::endl;
            return;
        }
    }
    std::cout << "Album not found" << std::endl;
}
*/
void CDCase::displayCollection() 
{   //TODO: Change this later to be more visually appealing
    //      Artist: 30 spaces  Title: 40 Spaces   Year: 10  Country(2-letter code): 8    Fav: 5 
    //
    std::cout << "                                          Your CD Collection" << std::endl;
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
    std::cout << Collection.size() << " album(s) owned" << "\n\n";
}


void CDCase::addtoFavorites(string artist, string album)  //Fix the favorite system, deleting a favorited album will still count it as a favorite
{
    bool notInFavorites = true;
    if(Favorites.size() != 5)
    {
        for(auto fav : Favorites)
        {
            if(fav.Artist == artist && fav.Title == album)
            {
                notInFavorites = false;
                break;
            }
        }
        for(auto &cd : Collection)
        {
            if(cd.Artist == artist && cd.Title == album && notInFavorites)
            {
                cd.Fav = true;
                Favorites.push_back(cd); //might have to change this back to Favorites.push_back(cd)
                std::cout << "Album added to favorites" << std::endl;
                return;
                
            }
        }
        std::cout << "The album isn't in your collection." << std::endl;
    } else if(notInFavorites == false){
        std::cout << "This album is already a favorite" << std::endl;
    } else {
        std::cout << "You already have 5 favorite albums, album not added to favorites." << std::endl;
    }   
}



void CDCase::removeFavorite(string artist, string album) 
{
    for(int i = 0; i < Favorites.size(); i++)
    {
        if(Favorites.at(i).Artist == artist && Favorites.at(i).Title == album)
        {
            Favorites.at(i).Fav = false;
            Favorites.erase(Favorites.begin() + i);
            std::cout << "Album removed from favorites" << std::endl;
            return;
        }
    }
    std::cout << "Album not found in favorites";
}



void CDCase::addtoWishlist(string artist, string title, int year, string country)   // sort wishlist after
{
    CD newcd = CD(artist, title, year, country);
    bool collec_found = false;
    bool wishl_found = false;
    for(auto &cd : Collection)
    {
        if(newcd.Artist == cd.Artist && newcd.Title == cd.Title)
        {
            collec_found = true;
        }
    }
    for(auto &cd : Wishlist)
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
        std::cout << newcd.Title << " by " << newcd.Artist << " added to your wishlist" << std::endl;
        
    }
            
}


void CDCase::removeWish(string artist, string title, bool moveToCollection) //sort after
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



void CDCase::displayWishlist() 
{  // TODO: Fix the ui to make it look more visually appealing and informative
    std::cout << "                                         Your Wishlist" << std::endl;
    std::cout << "+-------------------------------+----------------------------------------+----------+---------+" << std::endl;                                         
    std::cout << "|             Artist            |                 Title                  |   Year   | Country |" << std::endl;
    std::cout << "+-------------------------------+----------------------------------------+----------+---------+" << std::endl; 
    //            | The Cure                      | Disintegration                         |   1989   |   US    | separators and bottom borders part of loop
    //            +-------------------------------+----------------------------------------+----------+---------+   
    for(auto &cd : Wishlist)
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
        mainStr += "|   " + cd.Country + "    |";
        std::cout << mainStr << "\n" << "+-------------------------------+----------------------------------------+----------+---------+" << std::endl;
    }  
    std::cout << Wishlist.size() << " albums in your wishlist" << "\n\n";
}



void CDCase::saveToFile() //TODO
{

}



void CDCase::readFromFile() //TODO
{

}


    




    



    


