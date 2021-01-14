##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=3_2_1st_KruskalMST
ConfigurationName      :=Debug
WorkspacePath          :=/home/souvik/Documents/MyCourses/Stanford-AlgorithmCourse/StanfordDSAWorkspace/Greedy_Algorithms_MST_Dynamic_Programming
ProjectPath            :=/home/souvik/Documents/MyCourses/Stanford-AlgorithmCourse/StanfordDSAWorkspace/Greedy_Algorithms_MST_Dynamic_Programming/Week2
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Souvik Biswas
Date                   :=14/01/21
CodeLitePath           :=/home/souvik/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="3_2_1st_KruskalMST.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/subtree.cpp$(ObjectSuffix) $(IntermediateDirectory)/edge.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/souvik/Documents/MyCourses/Stanford-AlgorithmCourse/StanfordDSAWorkspace/Greedy_Algorithms_MST_Dynamic_Programming/Week2/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/subtree.cpp$(ObjectSuffix): subtree.cpp $(IntermediateDirectory)/subtree.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/souvik/Documents/MyCourses/Stanford-AlgorithmCourse/StanfordDSAWorkspace/Greedy_Algorithms_MST_Dynamic_Programming/Week2/subtree.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/subtree.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/subtree.cpp$(DependSuffix): subtree.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/subtree.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/subtree.cpp$(DependSuffix) -MM subtree.cpp

$(IntermediateDirectory)/subtree.cpp$(PreprocessSuffix): subtree.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/subtree.cpp$(PreprocessSuffix) subtree.cpp

$(IntermediateDirectory)/edge.cpp$(ObjectSuffix): edge.cpp $(IntermediateDirectory)/edge.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/souvik/Documents/MyCourses/Stanford-AlgorithmCourse/StanfordDSAWorkspace/Greedy_Algorithms_MST_Dynamic_Programming/Week2/edge.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/edge.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/edge.cpp$(DependSuffix): edge.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/edge.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/edge.cpp$(DependSuffix) -MM edge.cpp

$(IntermediateDirectory)/edge.cpp$(PreprocessSuffix): edge.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/edge.cpp$(PreprocessSuffix) edge.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


