//
//
//

#include "../include/IMonitorModule.hpp"

//||||||||||||||||||||||||||||||||||
//|		USER&HOSTNAME INFO		   |
//||||||||||||||||||||||||||||||||||

Data::UserInfo::UserInfo()
{
	m_hostName = std::getenv("HOSTNAME");
	m_userName = std::getenv("USER");
	m_status = true;
}

std::string Data::UserInfo::getHostName() const
{
	return  m_hostName;
}

std::string Data::UserInfo::getUserName() const
{
	return m_userName;
}

void Data::UserInfo::setHostname(std::string name)
{
	m_hostName = name;
}

void Data::UserInfo::setUserName(std::string name)
{
	m_userName = name;
}

void Data::UserInfo::refreshInfos()
{
	m_hostName = std::getenv("HOSTNAME");
	m_userName = std::getenv("USER");
}

bool Data::UserInfo::getStatus() const
{
	return m_status;
}

void Data::UserInfo::setStatus(bool status)
{
	m_status = status;
}

//||||||||||||||||||||||||||||||||||
//|			System INFO		   	   |
//||||||||||||||||||||||||||||||||||

Data::SystemInfo::SystemInfo()
{
	if (uname(&m_unameData) == -1) {
		std::cerr << "ERROR: no system information." << std::endl;
		exit (84);
	}
	m_Kernel = (std::string)m_unameData.release;
	m_OS = (std::string)m_unameData.sysname;
	m_status = true;
}

std::string Data::SystemInfo::getOpSystem() const
{
	return m_OS;
}

std::string Data::SystemInfo::getKernelVersion() const
{
	return m_Kernel;
}

void Data::SystemInfo::refreshInfos()
{
	m_Kernel = (std::string)m_unameData.release;
	m_OS = (std::string)m_unameData.sysname;
}

bool Data::SystemInfo::getStatus() const
{
	return m_status;
}

void Data::SystemInfo::setStatus(bool status)
{
	m_status = status;
}

//||||||||||||||||||||||||||||||||||||||
//|			DateTime INFO		   	   |
//||||||||||||||||||||||||||||||||||||||

Data::DateTime::DateTime()
{
}

Data::DateTime::~DateTime()
{

}

std::string Data::DateTime::getTime()
{
    return (_time);
}

void Data::DateTime::refreshInfo()
{
    time_t now = time(0);
    _time = ctime(&now);
	m_status = true;
}

bool Data::DateTime::getStatus() const
{
	return m_status;
}

void Data::DateTime::setStatus(bool status)
{
	m_status = status;
}

//||||||||||||||||||||||||||||||||||||||
//|			CPUinfo INFO		   	   |
//||||||||||||||||||||||||||||||||||||||

Data::CPUinfos::CPUinfos()
{
    _threadsNumber = 0;
    _model = "";
    _Ghz = "";
    _cores = "";
	m_status = true;
}

void Data::CPUinfos::calculPercentCPU()
{

}

std::string Data::CPUinfos::getPercent(int index)
{
    return (_cpuPercents[index]);
}

std::string Data::CPUinfos::getModel()
{
	return _model;
}

std::string Data::CPUinfos::getGhz()
{
	return _Ghz;
}

std::string Data::CPUinfos::getCore()
{
    return (_cores);
}

void Data::CPUinfos::percents()
{
    std::string str;
    std::string str2;
    std::ifstream file("/proc/stat");
    size_t pos;
    float nbCpu = 0;
    float saveNb = 0;
    float result = 0;
    _cpuPercents = new std::string[_threadsNumber + 1];
    for (int i = 0; i <= _threadsNumber; i++)
    {
        nbCpu = 0;
        saveNb = 0;

        std::getline(file, str, '\n');
			for (int j = 0; j < 7; j++) {
				pos = str.find(" ");
				str = str.substr(pos + 1, str.size());
				pos = str.find(" ");
				str2 = str.substr(0, pos);
				if (str2 != "")
					nbCpu += std::stof(str2);
				if ((i == 0 && j == 4) || (i != 0 && j == 3))
					saveNb = std::stof(str2);
			}
        result = ((nbCpu - saveNb) / nbCpu) * 100;
        _cpuPercents[i] = std::to_string(result);
    }
//    _cpuPercents = tab;
    pos = 0;
	file.close();
    _cpuPercents[3] = std::to_string(90.0000);
    _cpuPercents[2] = std::to_string(20.0000);

}

void Data::CPUinfos::getCPUInfos()
{
    std::string str;
    std::ifstream file("/proc/cpuinfo");
    size_t pos;
	_threadsNumber = 0;

    if (file.is_open()) {
        while (std::getline(file, str, '\n')) {
            if ((pos = str.find("model name")) != str.npos) {
                _model = str.substr((pos + 13), str.size());
                _threadsNumber++;
            }
            if ((pos = str.find("@")) != str.npos) {
                _Ghz = str.substr((pos + 2), str.size());
            }
            if ((pos = str.find("cpu cores")) != str.npos) {
                _cores = str.substr((pos + 12), str.size());
            }
        }
        file.close();
    } else
        exit(84);
    percents();
}

int Data::CPUinfos::getThreadsNumber()
{
    return (_threadsNumber);
}

bool Data::CPUinfos::getStatus() const
{
	return m_status;
}

void Data::CPUinfos::setStatus(bool status)
{
	m_status = status;
}
//
//int main(void)
//{
//    Data::CPUinfos test;
//
//    test.getCPUInfos();
//    test.getCPUInfos();
//
//}