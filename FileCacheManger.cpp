//
// Created by michal on 12/28/18.
//

#include "FileCacheManger.h"

bool FileCacheManager:: isExist(string problem)  {
    string solution;
    try{
        pthread_mutex_lock(&mutexMap);
        solutions.at(problem);
        pthread_mutex_unlock(&mutexMap);
        return true;
    } catch (exception &e){
        pthread_mutex_unlock(&mutexMap);
        return false;
    }
}

string FileCacheManager::getSulotion(string problem)  {
    string solution;
    try{
        pthread_mutex_lock(&mutexMap);
        solutions.at(problem) = solution;
        pthread_mutex_unlock(&mutexMap);
        return solution;
    }catch (exception &e){
        pthread_mutex_unlock(&mutexMap);
        return nullptr;
    }
}

void FileCacheManager::saveSolution(string problem ,string solution)  {
    pthread_mutex_lock(&mutexFile);
    this->cacheFile.open("cache.txt");
    this->cacheFile << problem + "\n";
    this->cacheFile << solution + "\n";
    this->cacheFile.close();
    pthread_mutex_unlock(&mutexFile);

}
