#include <iostream>
#include <fstream>
#include <map>

class InventoryApp {
private:
    std::map<std::string, int> itemFrequency;

public:
    void readDataFromFile(const std::string& filename) {
        std::ifstream inputFile(filename);
        if (inputFile.is_open()) {
            std::string item;
            int frequency;
            while (inputFile >> item >> frequency) {
                itemFrequency[item] = frequency;
            }
            inputFile.close();
        } else {
            std::cerr << "Error using file: " << filename << std::endl;
        }
    }
    void displayMenu() {
        int choice;
        do {
            std::cout << "\nMenu:\n";
            std::cout << "1. Individual Frequency\n";
            std::cout << "2. Display List\n";
            std::cout << "3. Display Histogram\n";
            std::cout << "4. Exit\n";
            std::cout << "Choose your option";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    individualFrequency();
                    break;
                case 2:
                    displayFrequencyList();
                    break;
                case 3:
                    displayFrequencyHistogram();
                    break;
                case 4:
                    saveDataToFile("frequency.dat");
                    std::cout << "Data saved to frequency \n";
                    break;
                default:
                    std::cout << "Please enter a valid option.\n";
            }
        } while (choice != 4);
    }
    void individualFrequency() {
        std::string item;
        std::cout << "What item are you looking for: ";
        std::cin >> item;

        if (itemFrequency.find(item) != itemFrequency.end()) {
            std::cout << "Frequency of " << item << ": " << itemFrequency[item] << std::endl;
        } else {
            std::cout << "No such item found.\n";
        }
    }
    void displayFrequencyList() {
        for (const auto& entry : itemFrequency) {
            std::cout << entry.first << " " << entry.second << std::endl;
        }
    }
    void displayFrequencyHistogram() {
        for (const auto& entry : itemFrequency) {
            std::cout << entry.first << " ";
            for (int i = 0; i < entry.second; ++i) {
                std::cout << '*';
            }
            std::cout << std::endl;
        }
    }
    void saveDataToFile(const std::string& filename) {
        std::ofstream outputFile(filename);
        for (const auto& entry : itemFrequency) {
            outputFile << entry.first << " " << entry.second << std::endl;
        }
        outputFile.close();
    }
};

int main() {
    InventoryApp tracker;
    tracker.readDataFromFile("CS360_Project_Three_Input_File.txt");
    tracker.displayMenu();

    return 0;
}