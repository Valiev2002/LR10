#include <iostream>
#include <filesystem>
#include <string>                             //3 8 додел
namespace fs = std::filesystem;
int main()
{
	std::string command;
	std::cout << "What you want?  ";
	std::getline(std::cin, command);

	if (command == "Show current path")
	{
		std::cout << "Current path is " << fs::current_path() << "\n\n";
	}

	else if (command == "Show files") {
        for (auto &p : fs::directory_iterator(fs::current_path())) {
            std::cout << p.path().filename() << "\n";
        }
    }




	else if (command == "Size of the file")
	{
		for (auto& p : fs::directory_iterator(fs::current_path()))
		{
			std::cout << p.path().filename() << "\n";
		}
		std::cout << "\n";
		std::cout << "Enter the name of the file: ";
		std::string s;
		std::getline(std::cin, s);
		if (fs::exists(s))
		{
			std::cout << fs::file_size(s);
			std::cout << "\n\n";
		}
		else
		{
			std::cout << "Dont exist\n";
		}
	}




	else if (command == "Copy the file")
	{
		for (auto& p : fs::directory_iterator(fs::current_path()))
		{
			std::cout << p.path().filename() << "\n";
		}
		std::cout << "\n";
		std::cout << "Enter a name of the file: ";
		std::string s;
		std::getline(std::cin, s);
		if (fs::exists(s))
		{
			fs::copy_file(s, "Copy.txt");
		}
		else
		{
			std::cout << "The file with this name isn't exists.\n\n";
		}
	}


	else if (command== "Delete_the_file")
	{
		for (auto& p : fs::directory_iterator(fs::current_path()))
		{
			std::cout << p.path().filename() << "\n";
		}
		std::cout << "\n";
		std::cout << "Enter a name of the file: ";
		std::string s;
		std::getline(std::cin, s);
		if (fs::exists(s))
		{
			fs::remove(s);
		}
		else
		{
			std::cout << "The file with this name isn't exists.\n\n";
		}
	}



	else if (command == "Delete_the_path")
	{
		for (auto& p : fs::directory_iterator(fs::current_path()))
		{
			std::cout << p.path().filename() << "\n";
		}
		std::cout << "\n";
		std::cout << "Enter a name of deleted path: ";
		std::string s1;
		std::getline(std::cin, s1);
		fs::remove_all(s1);
		std::cout << "\n\n";
	}


	else if (command== "Move to the path")
	{
		std::cout << "If you want to go forward enter 1, else enter 0: ";
		bool n;
		std::cin >> n;
		if (n == 1)
		{
			for (auto& p : fs::directory_iterator(fs::current_path()))
			{
				std::cout << p.path().filename() << "\n";
			}
			std::cout << "\n";
			std::cout << "Enter a name of a needed path: ";
			std::string s2;
			std::getline(std::cin, s2);
			fs::current_path(S4);
			std::cout << "Current path is " << (fs::current_path()) << "\n\n";
		}
		else
		{
			std::cout << "Enter a name of a needed path: ";
			std::string s2;
			std::getline(std::cin, s2);
			fs::current_path(fs::current_path().remove_filename());
			std::cout << "Current path is " << fs::current_path() << "\n\n";
		}
	}


	else if (command == "Rename_the_file")
	{
		for (auto& p : fs::directory_iterator(fs::current_path()))
		{
			std::cout << p.path().filename() << "\n";
		}
		std::cout << "\n";
		std::cout << "Enter a name of a needed file: ";
		std::string s3;
		std::getline(std::cin, s3);
		if (fs::exists(s3))
		{
			std::cout << "Enter a new name of a needed file: ";
			std::string s4;
			std::getline(std::cin, s4);
			fs::rename(s3, s4);
			std::cout << "Done.\n\n";
		}
		else
		{
			std::cout << "The file with this name isn't exists.\n\n";
		}
	}

	else if (command == "Rename_the_path")
	{
		for (auto& p : fs::directory_iterator(fs::current_path()))
		{
			std::cout << p.path().filename() << "\n";
		}
		std::cout << "\n";
		std::cout << "Enter a name of a needed path: ";
		std::string s5;
		std::getline(std::cin, s5);
		if (fs::exists(s5))
		{
			std::cout << "Enter a new name of a needed path: ";
			std::string s6;
			std::getline(std::cin, s6);
			fs::rename(s5, s6);
			std::cout << "Done.\n\n";
		}
		else
		{
			std::cout << "The path with this name isn't exists.\n\n";
		}
	}

	//10

	else if (command == "Move_the_file")
	{
		for (auto& p : fs::directory_iterator(fs::current_path()))
		{
			std::cout << p.path().filename() << "\n";
		}
		std::cout << "\n";
		std::cout << "Enter a name of a needed file: ";
		std::string s7;
		std::getline(std::cin, s7);
		if (fs::exists(s7))
		{
			std::cout << "Enter a new name of a needed path way: ";
			std::string S10;
			std::getline(std::cin, S10);
			fs::path old_path;
			fs::path new_path;
			old_path = fs::current_path();
			old_path /= s7;
			fs::current_path(S10);
			new_path = fs::current_path();
			new_path /= s7;
			fs::rename(old_path, new_path);
			std::cout << "Done.\n\n";
		}
		else
		{
			std::cout << "Error.\n\n";
		}
	}
	//3
    else if (command == "Create new path")
    {
        for (auto& p : fs::directory_iterator(fs::current_path()))
        {
            std::cout << p.path().filename() << "\n";
        }
        std::cout << "\n";
        std::cout << "Enter a name of new path: ";
        std::string s8;
        std::getline(std::cin, s8);
        if (fs::exists(s8))
        {
            std::cout << "Already exists.\n\n";
        }
        else
        {
            fs::create_directory(s8);
            std::cout << "Done.\n\n";
        }
    }
	return 0;
}