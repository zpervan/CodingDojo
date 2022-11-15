#include "TestingGround/proto_lib/example.pb.h"

#include <fstream>
#include <experimental/filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;

int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    const std::string file_path{fs::current_path().c_str() + std::string("/newfile.txt")};
    std::cout << "File path: " << file_path << "\n";

    // Serializing data
    {
        CodingDojo::AddressBook addressBook;

        {
            CodingDojo::Person* person1 = addressBook.add_people();
            person1->set_name("Zvonimir");
            person1->set_email("crazy_email");
            person1->set_id(1);
        }

        {
            CodingDojo::Person* person2 = addressBook.add_people();
            person2->set_name("Cfonimir");
            person2->set_email("crazy_email2");
            person2->set_id(2);
        }

        {
            CodingDojo::Person* person3 = addressBook.add_people();
            person3->set_name("Zvonimia");
            person3->set_email("crazy_email3");
            person3->set_id(4);
        }

        std::fstream outfile{file_path, std::ios::out | std::ios::trunc | std::ios::binary};

        if(addressBook.SerializeToOstream(&outfile))
        {
            std::cout << "Serialization successful\n";
            outfile.close();
        }
        else
        {
            std::cerr << "Failed to serialize data\n";
        }
    }

    // Reading from previously serialized data
    {
        std::fstream infile{file_path, std::ios::in | std::ios::binary};

        CodingDojo::AddressBook newAddressBook;
        if (newAddressBook.ParseFromIstream(&infile))
        {
            std::cout << "Serialization successful\n";
            infile.close();
        }
        else
        {
            std::cerr << "Failed to parse data\n";
        }

        for (const auto& person : newAddressBook.people())
        {
            std::cout << "----- Contact " << person.id() << " -----\n";
            std::cout << "Name: " << person.name() << "\n";
            std::cout << "E-Mail: " << person.email() << "\n";
        }
    }

    google::protobuf::ShutdownProtobufLibrary();

    return EXIT_SUCCESS;
}