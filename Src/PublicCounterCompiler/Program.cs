// =====================================================================
// <copyright file="Program.cs" company="Advanced Micro Devices, Inc.">
//    Copyright (c) 2011-2019 Advanced Micro Devices, Inc. All rights reserved.
// </copyright>
// <author>
//    AMD Developer Tools Team
// </author>
// <summary>
//    Given an ordered internal counter definition file and the derived (e.g.: public)
//    definitions, produces c++ code to define them for the run-time.
// </summary>
// =====================================================================
namespace PublicCounterCompiler
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Windows.Forms;
    using System.Diagnostics;

    /// <summary>
    /// A program which compiles the derived counters definitions into C++ files.
    /// </summary>
    public class Program
    {
        /// <summary>
        /// The main entry point to the program.
        /// </summary>
        /// <param name="args">cmd line arguments</param>
        [STAThread]
        public static void Main(string[] args)
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            // set output paths
            const string compilerOutputFolder = "Output\\";
            int endPath = Application.StartupPath.IndexOf(compilerOutputFolder) + compilerOutputFolder.Length;

            if (compilerOutputFolder.Length == endPath)
            {
                MessageBox.Show(Application.ProductName + " was started out of unexpected folder.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            string gpaPath = GPATools.Gpa.GetGpuPerfApiPath();

            // Derived counter definition input
            var counterCompiler = new CounterCompiler();

            CounterCompiler.DerivedCounterFileInput counterPath = new CounterCompiler.DerivedCounterFileInput
            {
                rootFilename = GPATools.Gpa.PublicStr,
                compilerInputPath = gpaPath + GPATools.Gpa.CounterDefDir,
                autoGenCompilerInputFilePath = gpaPath + GPATools.Gpa.AutoGenPublicCounterInputDir,
                outputDirectory = gpaPath + GPATools.Gpa.AutoGenCounterGeneratorOutDir,
                counterListOutputDirectory = gpaPath + GPATools.Gpa.CounterListOutDir,
                testOutputDirectory = gpaPath + GPATools.Gpa.AutoGenTestOutDir
            };

            counterCompiler.derivedCounterFileInput = counterPath;

            var form = Form1.Instance(counterCompiler);

            // handle operational mode
            if (args.Length == 0)
            {
                counterCompiler.isConsoleApp = false;
                Application.Run(form);
                GPATools.CMakeGenerator.Init = GPATools.CounterDefCMakeGenerator.Init;
                GPATools.CMakeGenerator.ProcessFile = GPATools.CounterDefCMakeGenerator.ProcessFiles;
                GPATools.CMakeGenerator.CMakeWriter = GPATools.CounterDefCMakeGenerator.CMakeWriter;
                GPATools.CMakeGenerator.AddDirectory(GPATools.Gpa.GetGpuPerfApiPath() + "GPA\\Src\\AutoGenerated");
                GPATools.CMakeGenerator.GenerateCMakeFiles();
                return;
            }

            if (args.Length == 2
                || args.Length == 7
                || args.Length == 8)
            {
                // We can do this!
            }
            else
            {
                Console.WriteLine("Usage: PublicCounterCompiler.exe");
                Console.WriteLine("   - using no parameters will open the user interface");
                Console.WriteLine("Usage: PublicCounterCompiler [API] [HW generation]");
                Console.WriteLine(
                    "   opens the user interface and populates the input fields with the following parameters:");
                Console.WriteLine("   [API] - the API to compile counters for (ex: GL, CL, DX11, etc)");
                Console.WriteLine(
                    "   [HW generation] - the generation to compile counters for (ex: R10xx, R11xx, R12xx, etc)");
                Console.WriteLine(
                    "Usage: PublicCounterCompiler [counter names file] [Public counter definition file] [output dir] [API] [GPU]");
                Console.WriteLine(
                    "   [counter names file] - text file containing hardware counter names and type (CounterNames[API][GEN].txt)");
                Console.WriteLine(
                    "   [Public counter definition file] - text file defining how the public counters are calculated (PublicCounterDefinitions*.txt)");
                Console.WriteLine(
                    "   [Output Dir] - the directory to generate the output in (Ex: the path to the Src/GPUPerfAPICounterGenerator directory)");
                Console.WriteLine(
                    "   [Counter List Output Dir] - the directory to generate the counter list text files in (Ex: the path to the Output/CounterListFiles directory)");
                Console.WriteLine(
                    "   [Test output Dir] - the directory to generate the test output in (Ex: the path to the Src/GPUPerfAPIUnitTests/counters directory)");
                Console.WriteLine(
                    "   [API] - the API to compile counters for (ex: GL, CL, DX11, etc)");
                Console.WriteLine(
                    "   [HW generation] - the generation to compile counters for (ex: R10xx, R11xx, R12xx, etc)");
                Console.WriteLine(
                    "   {ASIC} - name of the ASIC (ex: baffin)");
                return;
            }

            if (args.Length == 2)
            {
                counterCompiler.isConsoleApp = false;

                form.apiName.Text = args[0];
                form.GPUFamily.Text = args[1];
                Application.Run(form);
                GPATools.CMakeGenerator.Init = GPATools.CounterDefCMakeGenerator.Init;
                GPATools.CMakeGenerator.ProcessFile = GPATools.CounterDefCMakeGenerator.ProcessFiles;
                GPATools.CMakeGenerator.CMakeWriter = GPATools.CounterDefCMakeGenerator.CMakeWriter;
                GPATools.CMakeGenerator.AddDirectory(GPATools.Gpa.GetGpuPerfApiPath() + "GPA\\Src\\AutoGenerated");
                GPATools.CMakeGenerator.GenerateCMakeFiles();
            }
            else if (args.Length == 7)
            {
                counterCompiler.LoadFilesAndGenerateOutput("Public", args[0], args[1], args[2], args[3], args[4], args[5], args[6], string.Empty, form.DisplayMessageHandler, form.ErrorHandler);
            }
            else if (args.Length == 8)
            {
                counterCompiler.LoadFilesAndGenerateOutput("Public", args[0], args[1], args[2], args[3], args[4], args[5], args[6], "_" + args[7], form.DisplayMessageHandler, form.ErrorHandler);
            }
        }
    }
}

