class Vehicle
{
private:
    std::string brand;
    std::string model;
public:
    void SetBrand(std::string b);
    void SetModel(std::string m);
    
    std::string GetBrand();
    std::string GetModel();
    
    virtual void WriteTo(std::ostream& output) = 0; //for different types it's going to be different output. can be done to file/concole/?other stream?
    
    Vehicle();
    ~Vehicle();
};

