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
    void SaveFrom(std::ifstream& file_stream);
    void ShowElements();
    
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
