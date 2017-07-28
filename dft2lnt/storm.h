/*
 * storm.h
 * 
 * Part of dft2lnt library - a library containing read/write operations for DFT
 * files in Galileo format and translating DFT specifications into Lotos NT.
 * 
 * @author Enno Ruijters, based on imca.h by Dennis Guck
 */

#ifndef STORM_H
#define STORM_H

#include "FileSystem.h"
#include <vector>

class Storm {
private:
	static double default_result;
public:
	class FileHandler {
	private:
		bool i_isCalculated;
		std::string i_calcCommand;
		double i_result;
	public:
		
		FileHandler(std::string calcCommand):
			i_isCalculated(false),
			i_calcCommand(calcCommand),
			i_result(default_result) {
		}
		
		/**
		 * Read the result from the specified STORM output file.
		 * Use this for STORM output that is the result of a STORM
		 * input file generated by the SAME or equivalent object.
		 * Obtain the result with getResult().
		 * @param file The STORM output file in which the result can be found.
		 */
		virtual int readOutputFile(const File& file);
		
		/**
		 * Return the result previously read with readOutputFile().
		 * @return The result of the calculation.
		 */
		virtual double getResult();
	};
};

#endif
