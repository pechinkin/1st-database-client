class Client {
private:
    Vehicle*** garage = nullptr;
    int size[3];
public:
    void AddElement(Vehicle &a);
    void DeleteElement(int row, int element);
    int GetSize();

    void RestoreFrom(std::ifstream& file_stream);
    void ShowElements();
    void Menu();

    Client();
};

Client::Client() {
    for (int i = 0; i < 3; i++) {
        size[i] = 0;
    }
    garage = new Vehicle**[3];
    garage[0] = new Vehicle*[0];
    garage[1] = new Vehicle*[0];
    garage[2] = new Vehicle*[0];
}

int Client::GetSize() {
    return size[0] + size[1] + size[2];
}

void Client::AddElement(Vehicle &a) {
    int m = -1;
    switch (a.GetType()) {
        case 'e':
            m = 0;
            break;
        case 's':
            m = 1;
            break;
        case 'r':
            m = 2;
            break;
        default:
            std::cout << "[some problem occurred]" << std::endl;
            return;
    }
    Vehicle** new_garage = new Vehicle*[size[m] + 1];
    for (int i = 0; i < size[m]; i++) {
        new_garage[i] = garage[m][i];
    }
    new_garage[size[m]] = &a;
    delete[] garage[m];
    garage[m] = new_garage;
    size[m]++;
    std::cout << "[element added]" << std::endl;
}

void Client::DeleteElement(int row, int element) {
    if (row >= 0 && row < 3 && element >= 0 && element < size[row]) {
        Vehicle** new_garage = new Vehicle*[size[row] - 1];
        int newIndex = 0;
        for (int i = 0; i < size[row]; i++) {
            if (i != element) {
                new_garage[newIndex] = garage[row][i];
                newIndex++;
            }
        }
        delete[] garage[row];
        garage[row] = new_garage;
        size[row]--;
        std::cout << "[element deleted]" << std::endl;
    } else {
        std::cout << "[invalid row or element number - deleting hasn't proceed]" << std::endl;
    }
}

void Client::ShowElements() {
    std::cout << "--list of elements--"<<std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i << ':' << std::endl;
        for (int n = 0; n < size[i]; n++) {
            std::cout << garage[i][n];
        }
        std::cout << std::endl;
    }
    std::cout << "--end of list--"<<std::endl;
}

void Client::Menu()
{
    int x = 0;
    while (x != 7)
    {
        std::cout << "1. Add vehicle" << std::endl;
        std::cout << "2. Delete vehicle" << std::endl;
        std::cout << "3. Show garage" << std::endl;
        std::cout << "4. Sort by brand" << std::endl;
        std::cout << "5. Save to file" << std::endl;
        std::cout << "6. Restore from file" << std::endl;
        std::cout << "7. Exit" << std::endl;
        if (!(std::cin >> x) || x > 7 || x < 1 )
        {
            std::cout << "[incorrect. try again]" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            switch (x) {
                case 1:
                    std::cout << ".1\n";
                    break;
                case 2:
                    std::cout << ".2\n";
                    break;
                case 3:
                    std::cout << ".3\n";
                    break;
                case 4:
                    std::cout << ".4\n";
                    break;
                case 5:
                    std::cout << ".5\n";
                    break;
                case 6:
                    std::cout << ".6\n";
                    break;
                    
                default:
                    break;
            }
        }
    }
    std::cout << "Exiting... Do you want to save to file?\n1 - yes, 2/other - no" << std::endl;
    std::cin >> x;
    if (x == 1)
    {
        std::cout << "Saving" << std::endl;
    }
    std::cout << "Exit done" << std::endl;
};

