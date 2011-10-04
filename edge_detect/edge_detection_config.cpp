//	-------------------------------------------------------------------------------------------------------------	 	//
// 														Variants of Self-Organizing Maps																											//
// Studienarbeit in Computer Vision at the Chair of Patter Recognition Friedrich-Alexander Universitaet Erlangen		//
// Start:	15.11.2010																																																//
// End	:	16.05.2011																																																//
// 																																																									//
// Ralph Muessig																																																		//
// ralph.muessig@e-technik.stud.uni-erlangen.de																																			//
// Informations- und Kommunikationstechnik																																					//
//	---------------------------------------------------------------------------------------------------------------	//


#include "edge_detection_config.h"

#ifdef VOLE_GUI
#include <QVBoxLayout>
#endif // VOLE_GUI

using namespace boost::program_options;


EdgeDetectionConfig::EdgeDetectionConfig(std::string prefix) : Config(prefix) {
	#ifdef WITH_BOOST
		initBoostOptions();
	#endif // WITH_BOOST
}


#ifdef WITH_BOOST
void EdgeDetectionConfig::initBoostOptions() {
	options.add_options()
		// global section
		(key("graphical"), bool_switch(&isGraphical)->default_value(false),
			 "Show graphical output during runtime")
		(key("input,I"), value(&input_dir),
		 "Image to process")
		(key("output,O"), value(&output_dir)->default_value("/tmp/"),
		 "Output directory")
		(key("algorithm,A"), value(&algorithm)->default_value("SOM"),
		"Edge detection algorithm: SOM, GTM")		 
		(key("mode,M"), value(&mode)->default_value("learn"),
		"Operating mode: learn, apply, visualize")
		(key("linearization,L"), value(&linearization)->default_value("NONE"),
		"Type of linearization: NONE, SFC (Space Filling Curve)")
		(key("somFile"), value(&som_file),
		 "File containing offline-trained SOM")
		(key("msiName"), value(&msi_name)->default_value(""),
		 "Name of the multispectral image")
		(key("somWidth"), value(&som_width)->default_value(120),
		 "Width of the SOM")
		(key("somHeight"), value(&som_height)->default_value(1),
		 "Height of the SOM")
		(key("withUMap"), value(&withUMap)->default_value(1),
		 "Use unified distance map for weighted graphs.\nCan be used by DD,SOM and GTM")
		(key("scaleUDistance"), value(&scaleUDistance)->default_value(1.0),
		 "Scale factor, how much percent of the weighting factors is used.\nCan be used by DD,SOM and GTM")
		(key("withGraph"), value(&graph_withGraph)->default_value(1),
		 "Use graph topology for SOM")
		(key("forceDD"), value(&forceDD)->default_value(0),
		 "Use direct distance for edge detection on a graph-trained SOM")		 
		(key("initialDegree"), value(&sw_initialDegree)->default_value(8),
		 "Degree of every vertex ")          
		(key("graph_type"), value(&graph_type)->default_value("MESH"),
		 "Topology of the graph\nAllowed values: RING | MESH | MESH_P")
		(key("sw_model"), value(&sw_model)->default_value("BETA"),
		 "Type of transforming a graph into small world graph\nAllowed values: BETA | PHI")     
		(key("beta"), value(&sw_beta)->default_value(0.0),
		 "Probability for rewireing an edge using the beta model")
		(key("phi"), value(&sw_phi)->default_value(0.0),
		 "Percentage rewired edges using the phi model")     
		(key("somMaxIter"), value(&som_maxIter)->default_value(40000),
		 "Number of training iterations for the SOM")
		(key("somLearnStart"), value(&som_learnStart)->default_value(0.1),
		 "Learning rate at the beginning")
		(key("somLearnEnd"), value(&som_learnEnd)->default_value(0.001),
		 "Learning rate at the end of the training process")
		(key("somRadiusStart"), value(&som_radiusStart)->default_value(4.),
		 "Initial neighborhood radius")
		(key("somRadiusEnd"), value(&som_radiusEnd)->default_value(1.),
		 "Neighborhood radius at the end of the training process")
		(key("rbfActFunc"), value(&gtm_actfn)->default_value("GAUSSIAN"),
		 "Activation function for the RBF network.\nAllowed values: GAUSSIAN | TPS | R4LOGR")		 
		(key("rbfSize"), value(&gtm_numRbf)->default_value(4),
		 "RBF network shape will contain rbfSize x rbfSize hidden units and rbf output units")
		(key("latentSize"), value(&gtm_numLatent)->default_value(15),
		 "Latent space will contain latentSize x latentSize latent variables")
		(key("emIterations"), value(&gtm_numIterations)->default_value(30),
		 "Number of iterations before the EM algorithm terminates")
		(key("samplePercentage"), value(&gtm_samplePercentage)->default_value(0.1),
		 "Percentage of randomly chosen input samples(0.0 to 1.0)")
		 (key("fixedSeed"), value(&fixedSeed)->default_value(false),
		 "Fix seeds for random generators")
		;
}
#endif // WITH_BOOST

std::string EdgeDetectionConfig::getString() const {
	std::stringstream s;
	if (prefix_enabled) {
		s << "[" << prefix << "]" << std::endl;
	}
	s	<< "verbose=" << verbosity
		<< " # verbosity level: 0 = silent, 1 = normal, 2 = much output, 3 = insane" << std::endl
		<< "graphical=" << isGraphical << " # Show any graphical output during runtime" << std::endl
		<< "input=" << input_dir << " # Image to process" << std::endl
		<< "output=" << output_dir << " # Working directory" << std::endl
		<< "algorithm=" << algorithm << "#  Set the training algorithm : GTM, SOM" << std::endl
		<< "mode=" << mode << " # Set the operating mode: -M <learn> | <apply> | <visualize>" << std::endl
		<< "linearization=" << linearization << "#  Set the linearization type : NONE, SFC (Space-filling curves)" << std::endl
		<< "somFile=" << som_file << " # Specify the path to a saved som file to use a trained som!" << std::endl
		<< "msiName=" << msi_name << " # Name of the multispectral image" << std::endl
		<< "somWidth=" << som_width << " # Width of the SOM" << std::endl
		<< "somHeight=" << som_height << " # Height of the SOM" << std::endl
		<< "withGraph=" << graph_withGraph << " # Use a graph topology for the" << std::endl
		<< "withUMap=" << withUMap << " # Use weighted edges according to the Unified distance Map" << std::endl		
		<< "scaleUDistance=" << scaleUDistance << " # Scaling factor for the weighting function : 0.0 <= scaleUDistance <= 1.0" << std::endl		
		<< "forceDD=" << forceDD << " # Calculate the distances directly, although the training has been done on a graph" << std::endl		
		<< "initialDegree=" << sw_initialDegree << " # The wished degree for each node (may differ at border nodes, if graph is non-periodic)" << std::endl		
		<< "graph_type=" << graph_type << " # Topology of the graph : MESH | MESH_P (periodic)" << std::endl				
		<< "sw_model=" << sw_model << " # Generation algorithm for Small-World graphs : BETA | PHI" << std::endl				
		<< "beta=" << sw_beta << " # beta-percent of rewired edges" << std::endl
		<< "phi=" << sw_phi << " # phi-percent of edges forced to be shortcuts" << std::endl
		<< "somMaxIter=" << som_maxIter << " # Number of training iterations for the SOM" << std::endl
		<< "somLearnStart=" << som_learnStart << " # Start value for the learning rate in SOM" << std::endl
		<< "somLearnEnd=" << som_learnEnd << " # End value for the learning rate in SOM" << std::endl
		<< "somRadiusStart=" << som_radiusStart << " # Start value for the radius of the neighborhood function in SOM" << std::endl
		<< "somRadiusEnd=" << som_radiusEnd << " # End value for the radius of the neighborhood function in SOM" << std::endl
		<< "rbfActFunc=" << gtm_actfn << " # Activation function for the radial basis units : GAUSSIAN | TPS | R4LOGR" << std::endl
		<< "rbfSize=" << gtm_numRbf << " # Number of hidden units (= rbfSize x rbfSize )" << std::endl
		<< "latentSize=" << gtm_numLatent << " # Number of latent variables (= latentSize x latentSize )" << std::endl
		<< "emIterations=" << gtm_numIterations << " # Number of training iterations used for the GTM algorithm" << std::endl
		<< "samplePercentage=" << gtm_samplePercentage << " # Percentage of used multispectral input vectors during the EM training" << std::endl
		<< "fixedSeed=" << fixedSeed << " # Initialize the random number generators with a fixedSeed " << std::endl
		
	;
	return s.str();
}

#ifdef VOLE_GUI
QWidget *EdgeDetectionConfig::getConfigWidget() {
	this->initConfigWidget();
	QVBoxLayout *data_access_config = new QVBoxLayout();
	// (..)
	configWidget->setLayout(layout);
	layout->addLayout(data_access_config);
	configWidget->setLayout(layout);
	return configWidget;
}

void EdgeDetectionConfig::updateValuesFromWidget() {
//	{ std::stringstream s; s << edit_min_ev_ratio->text().toStdString();
//		s >> minimum_eigenvalue_ratio; }
}
#endif// VOLE_GUI

