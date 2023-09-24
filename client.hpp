class Client
{
private:
    Vehicle* garage = nullptr;
    
public:
    void AddElement(int n[2]);
    void DeleteElement(int n[2]);
    
    void WriteTo(std::ostream& output);
    void SaveFrom(std::ifstream& file_stream);
    
    Client();
    ~Client();
};
