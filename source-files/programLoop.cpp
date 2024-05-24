//#include <iostream>
//#include <vector>
#include "../headers/cdcase.hpp"
#include <cctype>
#include <cstddef>
#include <stdlib.h>
#include <cstdlib>
#include <string>
 



bool number(string stringstring)
{
    for(auto character : stringstring)
        {
            if(!(std::isdigit(character)))
            {
                return false;
            }
        }
    return true;
}


string getMenuInput(std::vector<string> availableOptions)
{
    string userOption;
        while(true)
        {
            std::cout << "Command: ";
            std::getline(std::cin, userOption);
            for(auto option : availableOptions)
            {
                if(userOption == option)
                {
                    return userOption;
                }
            }
            std::cout << "Not a valid input, please try again" << std::endl;
        }
}



void getCDInput(string &addArtist, string &addTitle, string &addYear, string &addCountry)  //for addCD and addToWishlist 
{
    bool artistCriteria = false;
    bool titleCriteria = false;
    bool yearCriteria = false;
    bool countryCriteria = false;

    while(true)
    {
        std::cout << "Enter an Artist: ";
        std::getline(std::cin, addArtist);
        if(addArtist.length() <= 30)
        {
            artistCriteria = true;
        }

        std::cout << "Enter an Album: ";
        std::getline(std::cin, addTitle);
        if(addTitle.length() <= 40)
        {
            titleCriteria = true;
        }


        std::cout << "Enter the year it was released: ";
        std::getline(std::cin, addYear);
        bool isNumber = number(addYear);
        if(isNumber && addYear.length() == 4)
        {
            yearCriteria = true;
        }

        std::cout << "Enter country of origin: ";
        std::getline(std::cin, addCountry);
        bool notString = number(addCountry);
        if(addCountry.length() == 2 && notString == false)
        {
            countryCriteria = true;
        }

        if(artistCriteria && titleCriteria && yearCriteria && countryCriteria)
        {
            break;
        } else {
            std::cout << "You entered an invalid value. Try Again" << std::endl;

        }
    }
}

void getSearchInfo(string &addArtist, string &addTitle)  //pretty much all other CDCase functions
{
    bool artistCriteria = false;
    bool titleCriteria = false;
   

    while(true)
    {
        std::cout << "Enter an Artist: ";
        std::getline(std::cin, addArtist);
        if(addArtist.length() <= 30)
        {
            artistCriteria = true;
        }

        std::cout << "Enter an Album: ";
        std::getline(std::cin, addTitle);
        if(addTitle.length() <= 40)
        {
            titleCriteria = true;
        }


        if(artistCriteria && titleCriteria)
        {
            break;
        } else {
            std::cout << "You entered an invalid value. Try Again" << std::endl;

        }
    }
    
}



void wishlistMenu(CDCase &collec, string &collectionSortingComparator, string &WishlistSortingComparator, string &addArtist, string &addTitle, string &addYear, string &addCountry)
{
    while(true)
    {
        system("clear");
        collec.displayWishlist();
        std::cout << "| Add to wishlist ('add') |  Delete Wish ('del') | Move to Collection ('move') | Sort Wishlist ('sort') |\n\n";
        std::vector<string> WishOptions = {"add", "del", "move", "sort", "back"};
        std::cout << "Type 'back' if you want to go back to your collection" << "\n\n";


        string userOption = getMenuInput(WishOptions);

        if(userOption == "add")
        {
            bool repeatAdd = true;
            while(true)
            {
                char yesOrNo;
                
                
                getCDInput(addArtist, addTitle, addYear, addCountry);
                int newYear = std::stoi(addYear);
                collec.addtoWishlist(addArtist, addTitle, newYear, addCountry);
                std::cout << "Would you like to add another album to your wishlist?(y/n) ";
                std::cin >> yesOrNo;
                std::cin.ignore(1, '\n');
                std::cout << "\n\n"; 
                if(yesOrNo == 'n')
                {
                    break;
                }
            }
        } else if(userOption == "del"){
            
            while(true)
            {
                char yesOrNo;
                

                getSearchInfo(addArtist, addTitle);
                collec.removeWish(addArtist, addTitle, false);
                std::cout << "Would you like to remove another album?(y/n)? ";
                std::cin >> yesOrNo;
                std::cin.ignore(1, '\n');
                std::cout << "\n\n"; 
                if(yesOrNo == 'n')
                {
                    break;
                }
            }
        } else if(userOption == "move"){
            while(true)
            {
                char yesOrNo;
                bool notQuit = true;

                getSearchInfo(addArtist, addTitle);
                collec.removeWish(addArtist, addTitle, true);
                std::cout << "Would you like to remove another album?(y/n)? ";
                std::cin >> yesOrNo;
                std::cin.ignore(1, '\n');
                std::cout << "\n"; 
                if(yesOrNo == 'n')
                {
                    collec.sortCD(collectionSortingComparator, "Collection");
                    break;
                }
            }
        } else if(userOption == "sort"){
            string sortBy;
            while(true)
            {
                std::cout << "Enter how you would like to sort the collection ('Artist', 'Title', 'Year', 'Country'): ";
                std::cin >> sortBy;
                std::cin.ignore(1, '\n');
                if(sortBy == "Artist" || sortBy == "Title" || sortBy == "Year" || sortBy == "Country")
                {
                    WishlistSortingComparator = sortBy;
                    break;
                }
                std::cout << "Not a valid option, try again" << std::endl;
            }
            collec.sortCD(WishlistSortingComparator, "Wishlist");
        } else if(userOption == "back"){
            return;
        } else {
            std::cout << "Some error occured somewhere I guess" << std::endl;
        }
        system("clear");
    }
}


void initialize()
{
    system("clear");
    CDCase collec;
    string collectionSortingComparator = "Artist";
    string wishlistSortingComparator = "Artist";

    std::vector<string> options;
    options = {"add", "delete", "sort", "add fav", "del fav", "wish", "quit"};
    



    //CDCase::readFromFile();
    std::cout << "=====================================================================================================\n";
    std::cout << "                                    Welcome to CD Collector!\n";
    std::cout << "====================================================================================================="<< "\n\n";

    while(true)
    {
        collec.displayCollection();
        std::cout << "| Add to Collection ('add') |     Remove Album ('delete')    | Sort Collection ('sort') |" << std::endl;
        std::cout << "| Add Favorite ('add fav')  |   Remove Favorite ('del fav')  |  Open Wishlist ('wish')  |\n\n";
        std::cout << "Type 'quit' if you want to exit the program" << "\n\n";
        

        string addArtist;
        string addTitle;
        string addYear;
        string addCountry;


        string userOption = getMenuInput(options);

        if(userOption == "add")
        {
            while(true)
            {
                char yesOrNo;
                
                getCDInput(addArtist, addTitle, addYear, addCountry);
                int newYear = std::stoi(addYear);
                collec.addCD(addArtist, addTitle, newYear, addCountry);
                std::cout << "Would you like to add another album(y/n)? ";
                
                std::cin >> yesOrNo;
                std::cin.ignore(1, '\n');
                std::cout << "\n\n"; 
                if(yesOrNo == 'n')
                {
                    break;
                }
            }
            collec.sortCD(collectionSortingComparator, "Collection");

        } else if (userOption == "delete") {
            while(true)
            {
                char yesOrNo;

                getSearchInfo(addArtist, addTitle);
                collec.removeCD(addArtist, addTitle);
                std::cout << "Would you like to remove another album?(y/n)? ";
                std::cin >> yesOrNo;
                std::cin.ignore(1, '\n');
                std::cout << "\n"; 
                if(yesOrNo == 'n')
                {
                    break;
                }

            }
        } else if (userOption == "sort") {
            string sortBy;
            while(true)
            {
                std::cout << "Enter how you would like to sort the collection ('Artist', 'Title', 'Year', 'Country'): ";
                std::cin >> sortBy;
                std::cin.ignore(1, '\n');
                if(sortBy == "Artist" || sortBy == "Title" || sortBy == "Year" || sortBy == "Country")
                {
                    collectionSortingComparator = sortBy;
                    break;
                }
                std::cout << "Not a valid option, try again" << std::endl;
            }
            collec.sortCD(collectionSortingComparator, "Collection");
        } else if (userOption == "add fav") {
            
            while(true)
            {
                char yesOrNo;
                
                getSearchInfo(addArtist, addTitle);
                collec.addtoFavorites(addArtist, addTitle);
                std::cout << "Would you like to add another album to favorites?(y/n)? ";
                std::cin >> yesOrNo;
                std::cin.ignore(1, '\n');
                std::cout << "\n"; 
                if(yesOrNo == 'n')
                {
                    break;
                }
            }
        } else if (userOption == "del fav") {
            while(true)
            {
                char yesOrNo;
                
                getSearchInfo(addArtist, addTitle);
                collec.removeFavorite(addArtist, addTitle);
                std::cout << "Would you like to add another album to favorites?(y/n)? ";
                std::cin >> yesOrNo;
                std::cin.ignore(1, '\n');
                std::cout << "\n"; 
                if(yesOrNo == 'n')
                {
                    break;
                }
            }

        } else if (userOption == "wish") {
            wishlistMenu(collec, collectionSortingComparator, wishlistSortingComparator, addArtist, addTitle, addCountry, addYear);
        } else if (userOption == "quit") {
            break;
        } else {
            std::cout << "Error Occured Somehow I Guess" << std::endl;
        }
        system("clear");
    }
    collec.sortCD("Artist", "Collection");
    collec.sortCD("Artist", "Wishlist");
    //CDCase::saveToFile();
}
