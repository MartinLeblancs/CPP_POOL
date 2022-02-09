//
//
//

#ifndef B_PDG_300_PAR_3_1_PDGRUSH3_MATTHIEU_QUERU_IMONITORMODULE_HPP
#define B_PDG_300_PAR_3_1_PDGRUSH3_MATTHIEU_QUERU_IMONITORMODULE_HPP

#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
#include <vector>
#include <sys/utsname.h>
#include <algorithm>

void core(char *);

namespace Data
{
	class UserInfo {
		public:
			UserInfo();
			virtual ~UserInfo(){};
			//
			std::string getUserName() const;
			std::string getHostName() const;
			void setUserName(std::string name);
			void setHostname(std::string name);
			bool getStatus() const;
			void setStatus(bool status);
			//
			void refreshInfos();
		private:
			std::string m_userName;
			std::string m_hostName;
			bool m_status;
	};

	class SystemInfo {
		public:
			SystemInfo();
			virtual ~SystemInfo(){};
			//
			std::string getOpSystem() const;
			std::string getKernelVersion() const;
			bool getStatus() const;
			void setStatus(bool status);
			//
			void refreshInfos();
			struct utsname m_unameData;
		private:
			std::string m_OS;
			std::string m_Kernel;
			bool m_status;
	};

	class DateTime {
		public:
            DateTime();
            virtual ~DateTime();
            std::string getTime();
			bool getStatus() const;
			void setStatus(bool status);
            void refreshInfo();
		private:
            std::string _time;
			bool m_status;
    };

	class CPUinfos {
        public:
        CPUinfos();
        virtual ~CPUinfos(){};
        void getCPUInfos();
        void calculPercentCPU();
        std::string getPercent(int index);
        std::string getCore();
		std::string getGhz();
		std::string getModel();
		bool getStatus() const;
		void setStatus(bool status);
        int getThreadsNumber();
        void percents();
        private:
        std::string _model;
        std::string _Ghz;
        std::string _cores;
        std::string *_cpuPercents;
        int _threadsNumber;
		bool m_status;

    };

	class RamInfo {
		public:
		private:
	};
}

#endif //B_PDG_300_PAR_3_1_PDGRUSH3_MATTHIEU_QUERU_IMONITORMODULE_HPP
