#pragma once
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "../Models/Project_path.h"

class Config
{
  public:
    Config()
    {
        reload();
    }
	// Метод reload()
    void reload()
    {
		// открывает файл settings.json, который находится по пути, заданному переменной project_path
        std::ifstream fin(project_path + "settings.json");
		// считывает содержимое файла в объект config типа json.
        fin >> config;
		// закрытие файла после окончания чтения. 
        fin.close();
    }
	// позволяет использовать объект Config как функцию, принимающую два параметра: setting_dir и setting_name.
    auto operator()(const string &setting_dir, const string &setting_name) const
    {
        return config[setting_dir][setting_name];
    }

  private:
    json config;
};
