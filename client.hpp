class Client {
private:
    Vehicle*** garage = nullptr;
    int size[3];
    Bike bikee;
    Bus buss;
    Car carr;
public:
    void AddElement(Vehicle &a);
    void AddVehicleFromConsole();
    void DeleteElement();
    void CopyElement();
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


void Client::AddVehicleFromConsole() {
    std::string brand, model, destination;
    int type, volume, power, landscape, color, sit_pas, max_pas;
    char gearbox;

    std::cout << "What vehicle? Bike - 0, Bus - 1, Car - 2: ";
    std::cin >> type;
    std::cin.ignore(); // Ignore the newline character

    switch (type) {
        case 0:
            std::cout << "Enter a brand: ";
            std::getline(std::cin, brand);
            if (brand.empty()) {
                std::cout << "Invalid input." << std::endl;
                return;
            }
            std::cout << "Enter a model: ";
            std::getline(std::cin, model);
            if (model.empty()) {
                std::cout << "Invalid input." << std::endl;
                return;
            }
            std::cout << "Enter a volume: ";
            if (!(std::cin >> volume) || volume < 0) {
                std::cout << "Invalid input." << std::endl;
                return;
            }
            std::cout << "Enter a power: ";
            if (!(std::cin >> power) || power < 0) {
                std::cout << "Invalid input." << std::endl;
                return;
            }
            std::cout << "Landscapes: 1/2/3\nEnter a landscape: ";
            if (!(std::cin >> landscape) || landscape < 0 || landscape > 3) {
                std::cout << "Invalid input." << std::endl;
                return;
            }
            

            bikee.SetBrand(brand);
            bikee.SetModel(model);
            bikee.SetVolume(volume);
            bikee.SetPower(power);
            bikee.SetLandscape(landscape);

            AddElement(bikee);
            break;

        case 1:
            std::cout << "Enter a brand: ";
            std::getline(std::cin, brand);
            if (brand.empty()) {
                std::cout << "Invalid input." << std::endl;
                return;
            }
            std::cout << "Enter a model: ";
            std::getline(std::cin, model);
            if (model.empty()) {
                std::cout << "Invalid input." << std::endl;
                return;
            }
            std::cout << "Enter a num of sit. pas: ";
            if (!(std::cin >> sit_pas) || sit_pas < 0) {
                std::cout << "Invalid input." << std::endl;
                return;
            }
            std::cout << "Enter a num of max. pas: ";
            if (!(std::cin >> max_pas) || max_pas < 0 || sit_pas > max_pas) {
                std::cout << "Invalid input." << std::endl;
                return;
            }
            std::cout << "Enter a destination: ";
            std::cin.ignore();
            std::getline(std::cin, destination);
            if (destination.empty()) {
                std::cout << "Invalid input." << std::endl;
                return;
            }

            buss.SetBrand(brand);
            buss.SetModel(model);
            buss.SetSittingPas(sit_pas);
            buss.SetMaxPas(max_pas);
            buss.SetDestination(destination);

            AddElement(buss);
            break;

        case 2:
            std::cout << "Enter a brand: ";
            std::getline(std::cin, brand);
            if (brand.empty()) {
                std::cout << "Invalid input." << std::endl;
                return;
            }
            std::cout << "Enter a model: ";
            std::getline(std::cin, model);
            if (model.empty()) {
                std::cout << "Invalid input." << std::endl;
                return;
            }
            std::cout << "Enter a volume: ";
            if (!(std::cin >> volume) || volume < 0) {
                std::cout << "Invalid input." << std::endl;
                return;
            }
            std::cout << "Enter a color[1red, 2blue, 3green, 4black, 5white, 6yellow]: ";
            if (!(std::cin >> color) || color < 1 ||color > 6) {
                std::cout << "c_1.Invalid input." << std::endl;
                return;
            }
            std::cout << "Enter a gearbox[a/m/r/c]: ";
            if (!(std::cin >> gearbox)) {
                std::cout << "g_1.Invalid input." << std::endl;
                return;
            }
            if ((gearbox != 'a')|| !(gearbox != 'm')|| !(gearbox != 'r')|| !(gearbox != 'c')) {
                std::cout << "g_2.Invalid input." << std::endl;
                return;
            }

            carr.SetBrand(brand);
            carr.SetModel(model);
            carr.SetVolume(volume);
            carr.SetColor(color);
            carr.SetGearbox(gearbox);
            AddElement(carr);
            break;

        default:
            std::cout << "-" << std::endl;
            break;
    }
}

void Client::DeleteElement() {
    int row, element;
    std::cout << "What vehicle do you want to delete? Bike - 0, Bus - 1, Car 2: ";
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

void Client::CopyElement()
{
    int row, element;
    std::cout << "What vehicle do you want to copy? Bike - 0, Bus - 1, Car 2: ";
    std::cin >> row;
    if (!(row >= 0 && row <3)) {
        std::cout << "[incorrect input]" << std::endl;
        return;
    }
    std::cout << ((row == 0)?"bikes":((row == 1)?"buses":"cars")) << ':' << std::endl;
    for (int i = 0; i != size[row]; i++) {
        std::cout << i << " - " << garage[row][i] << std::endl;
    }
    std::cout << "Which one do you want to copy?" << std::endl;
    std::cin >> element;
    if (!(element >= 0 && element < size[row])) {
        std::cout << "[incorrect input]" << std::endl;
        return;
    }
    AddElement(*garage[row][element]);
};

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
        std::cout << "4. Copy element" << std::endl;
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
                    AddVehicleFromConsole();
                    break;
                case 2:
                    DeleteElement();
                    break;
                case 3:
                    WriteElementsTo(std::cout);
                    break;
                case 4:
                    CopyElement();
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

