
#ifndef MagneticMCL_h
#define MagneticMCL_h

#ifdef __cplusplus
extern "C" {
#endif
    
void mcl_init();
void mcl_add_map(const void* input, unsigned int count, int floor);
void mcl_remove_map(int floor);
    
void mcl_start(double fraction, double alpha_slow, double alpha_fast);
void mcl_move(double dx, double dy, double distance_variance, double angle_variance_rads);
void mcl_measure_magnitude_based(double f, double variance, double distance_threshold, bool resample);
void mcl_measure_component_based(double f_x, double f_y, double f_z, double w, double x, double y, double z, double variance, double distance_threshold, bool resample);
void mcl_measure_angle_based(double f_x, double f_y, double f_z, double w, double x, double y, double z, double magnitude_variance, double angle_variance_rads, double dist_threshold, bool resample);
void mcl_pull_particles_to_nearest_milestones(double disance_threshold);

unsigned long mcl_particles_count(int floor);
void mcl_particles(void *buf, int floor);
    
void mcl_closest_line(void *input, void *output, int floor);
void mcl_closest_point(void *input, void *output, int floor);
void mcl_closest_milestone(void *input, void *output, int floor);
        
unsigned int mcl_clusters_count(int floor);
void mcl_cluster_sizes(void *output, int output_size);

void mcl_most_probable_position(void *output, int size, bool pull_to_nearest_milestone);
    
void mcl_test(void *buf);
    
#ifdef __cplusplus
}
#endif


#endif /* Magnetic_MCL_h */
