#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
using namespace std;
namespace fs=std::filesystem;
int main()
{
    fs::path cur_path, copy, new_path;
    std::string new_dir, file, del_dir, s, new2, dir;
    int x;
    cout<<"Привет,я-Джарвис.Что я могу сделать для тебя? "<<endl;
    cout << "1:Вывод на экран текущего каталога" <<
         "2:Вывод на экран содержимого каталога" <<
         "3:Создание каталога (папки) с предварительной проверкой на существование одноимённого каталога"<<
         "4:Вывод на экран размера файла "<<
         "5:Копирование файла"<<
         "6:Удаление файла" <<
         "7:Удаление каталога с файлами" <<
         "8:Перемещение по каталогам" <<
         "9:Переиминование файлов и каталогов" <<
         "10:Перемещение файлов и каталогов." << endl;
    cout << "key = " ;
    cin >> x;
    switch (x)
    {
        case 1:
            cur_p= fs::current_path();;
            cout<< "current path:" << cur_p <<endl;
            break;
        case 2:
            for(auto& p: fs::directory_iterator(fs::current_path()))
            {
                cur_p = p.path();
                cout << cur_p.filename() << endl;
            }
            break;
        case 3:
            cout << "enter a name :";
            std::getline(std::cin, new_dir);
            if (fs::exists(new_dir))
            {
                cout << "this directory already exists" << endl;
            }
            else
            {
                fs::create_directory(new_dir);
                cout << "Yes";
            }
            break;
        case 4:
            cout << "enter a file name: ";
            std::getline(std::cin, file);
            cur_p = fs::current_path() / file;
            std::ofstream(cur_p).put('a');
            std::cout << "File size = " << fs::file_size(cur_p) << endl;
            break;
        case 5:
            //сначала ввод файла, который копируем, потом ввод названия нового файла
            cout << "enter a file name:";
            std::getline(std::cin, s);
            if (fs::exists(s))
            {
                fs::copy_file(s, "Copy.txt");
            }
            else
            {
                std::cout << "The file with this name dont exists.\n\n";
            }
            break;
        case 6:
            std::getline(cin,file);
            cur_path = fs::current_path() / file;
            remove(cur_path);
            break;
        case 7:
            std::getline(cin, del_dir);
            cur_path = fs::current_path() / del_dir;
            fs::remove_all(cur_p);
            break;

        case 8:
            int key2 ;
            cout  << "1) вверх" << endl << "2) вниз" << endl;
            cin>>key2;
            switch (key2)
            {
                case 1:
                    std::getline(cin,dir);
                    cur_p = fs::current_path() /dir;
                    fs::create_directory(dir);
                    fs::current_path(cur_p);
                    cout << fs::current_path() << endl;
                    break;

                case 2:
                    cur_p = fs::current_path().remove_filename();
                    fs::current_path(cur_p);
                    cout << fs::current_path() << endl;
                    break;
            }

            break;
        case 9:
            int key1 ;
            cout  << "1) file" << endl << "2) dir" << endl;
            cin>>key1;
            switch (key1)
            {
                case 1:
                    std::getline(cin, file);
                    std::getline(cin, new2);
                    cur_p = fs::current_path() / file;
                    new2 = fs::current_path() / new2;
                    fs::rename(cur_p, new2);
                    break;

                case 2:
                    std::getline(cin,dir);
                    std::getline(cin, new2);
                    cur_p = fs::current_path() / dir;
                    cur_p = fs::current_path() / new2;
                    fs::rename(cur_p, new2);
                    break;
            }
        case 10:
            for (auto& p : fs::directory_iterator(fs::cur_path()))
            {
                std::cout << p.path().filename() << "\n";
            }
            std::cout << "\n";
            std::cout << "Enter a name of a needed file: ";
            std::string suv;
            std::getline(std::cin, suv);
            if (fs::exists(suv))
            {
                cout << "Enter a new name of a needed path: ";
                string bag;
                getline(std::cin, bag);
                fs::path cur_path;
                fs::path new_path;
                cur_path = fs::current_path();
                cur_path /= suv;
                fs::current_path(bag);
                new_path = fs::current_path();
                new_path /= bag;
                fs::rename(cur_path, new_path);
                cout << "Done.\n\n";
            }
            else
            {
                std::cout << "The file with this name isn't exists.\n\n";
            }
    }
    return 0;
}
