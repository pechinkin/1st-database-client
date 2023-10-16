class Client {
private:
    Vehicle*** garage = nullptr;
    int size[3];
public:
    void AddElement(Vehicle &a);
    void DeleteElement();
    int GetSize();

    void RestoreFrom(std::ifstream& file_stream);
    void WriteElementsTo(std::ostream& output);
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

void Client::DeleteElement() {
    int row, element;
    std::cout << "What vehicle do you want to delete? Bike - 0, Bike - 1, Car 2: ";
    std::cin >> row;
    if (!(row >= 0 && row <3)) {
        std::cout << "[incorrect input]" << std::endl;
        return;
    }
    std::cout << ((row == 0)?"bikes":((row == 1)?"buses":"cars")) << ':' << std::endl;
    for (int i = 0; i != size[row]; i++) {
        std::cout << i << " - " << garage[row][i] << std::endl;
    }
    std::cout << "Which one do you want to delete?" << std::endl;
    std::cin >> element;
    if (!(element >= 0 && element < size[row])) {
        std::cout << "[incorrect input]" << std::endl;
        return;
    }
//finally trying to delete
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
        }
        else {
            std::cout << "[invalid row or element number - deleting hasn't proceed]" << std::endl;
        }
}

void Client::WriteElementsTo(std::ostream& output) {
    for (int i = 0; i < 3; i++) {
        output << ((i == 0)?"bike":((i == 1)?"bus":"car")) << ':' << std::endl;
        for (int n = 0; n < size[i]; n++) {
            output << garage[i][n] << std::endl;
        }
        output << std::endl;
    }
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
                    DeleteElement();
                    break;
                case 3:
                    WriteElementsTo(std::cout);
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
    std::cout << "[exiting... Do you want to save to file?\n1 - yes, 2/other - no]" << std::endl;
    std::cin >> x;
    if (x == 1)
    {
        std::cout << "[saving..]" << std::endl;
    }
    std::cout << "[exit done]" << std::endl;
};

