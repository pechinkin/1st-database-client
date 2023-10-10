class Client
{
private:
    Vehicle* garage = nullptr;
    int size;
public:
    void AddElement(Vehicle &a);
    void DeleteElement(int n);
    int GetSize();
    
//    void WriteTo(std::ostream& output) const;
    void RestoreFrom(std::ifstream& file_stream);
    void ShowElements();
    void Menu();
    
    Client();
//    ~Client();//should add saving to file here as well
};

Client::Client()
{
    size = 0;
    garage = new Vehicle[0];
};

int Client::GetSize(){
    return size;
};

void Client::AddElement(Vehicle &a)
{
    Vehicle* new_garage = new Vehicle [size + 1];
    for (int i = 0; i != size; i++) {
        new_garage[i] = garage[i];
    }
    new_garage[size] = a;
    delete[] garage;
    garage = new_garage;
    size++;
};

void Client::DeleteElement(int n)
{
    if (n <= size)
    {
        Vehicle* new_garage = new Vehicle [size - 1];
        for (int i = 0; i != size; i++) {
            if (i < n)
            {
                new_garage[i] = garage[i];
            }
            if (i > n)
            {
                new_garage[i - 1] = garage[i];
            }
            
        }
        delete[] garage;
        garage = new_garage;
        size --;
    }
    else
    {
        std::cout << "number is more than max elem\n";
    }
};

void Client::ShowElements()
{
    for (int i = 0; i != size; i++) {
        std::cout << garage[i].GetBrand() << std::endl;
    }
};

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
            std::cout << "Incorrect. Try again" << std::endl;
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
