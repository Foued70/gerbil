#include "cieobserver.h"

const float CIEObserver::x[] = { 1.222E-07f, 9.1927E-07f, 5.9586E-06f, 3.3266E-05f, 0.000159952f, 0.00066244f, 0.0023616f, 0.0072423f, 0.0191097f, 0.0434f, 0.084736f, 0.140638f, 0.204492f, 0.264737f, 0.314679f, 0.357719f, 0.383734f, 0.386726f, 0.370702f, 0.342957f, 0.302273f, 0.254085f, 0.195618f, 0.132349f, 0.080507f, 0.041072f, 0.016172f, 0.005132f, 0.003816f, 0.015444f, 0.037465f, 0.071358f, 0.117749f, 0.172953f, 0.236491f, 0.304213f, 0.376772f, 0.451584f, 0.529826f, 0.616053f, 0.705224f, 0.793832f, 0.878655f, 0.951162f, 1.01416f, 1.0743f, 1.11852f, 1.1343f, 1.12399f, 1.0891f, 1.03048f, 0.95074f, 0.856297f, 0.75493f, 0.647467f, 0.53511f, 0.431567f, 0.34369f, 0.268329f, 0.2043f, 0.152568f, 0.11221f, 0.0812606f, 0.05793f, 0.0408508f, 0.028623f, 0.0199413f, 0.013842f, 0.00957688f, 0.0066052f, 0.00455263f, 0.0031447f, 0.00217496f, 0.0015057f, 0.00104476f, 0.00072745f, 0.000508258f, 0.00035638f, 0.000250969f, 0.00017773f, 0.00012639f, 9.0151E-05f, 6.45258E-05f, 4.6339E-05f, 3.34117E-05f, 2.4209E-05f, 1.76115E-05f, 1.2855E-05f, 9.41363E-06f, 6.913E-06f, 5.09347E-06f, 3.7671E-06f, 2.79531E-06f, 2.082E-06f, 1.55314E-06f };
const float CIEObserver::y[] = { 1.3398E-08f, 1.0065E-07f, 6.511E-07f, 3.625E-06f, 1.7364E-05f, 7.156E-05f, 0.0002534f, 0.0007685f, 0.0020044f, 0.004509f, 0.008756f, 0.014456f, 0.021391f, 0.029497f, 0.038676f, 0.049602f, 0.062077f, 0.074704f, 0.089456f, 0.106256f, 0.128201f, 0.152761f, 0.18519f, 0.21994f, 0.253589f, 0.297665f, 0.339133f, 0.395379f, 0.460777f, 0.53136f, 0.606741f, 0.68566f, 0.761757f, 0.82333f, 0.875211f, 0.92381f, 0.961988f, 0.9822f, 0.991761f, 0.99911f, 0.99734f, 0.98238f, 0.955552f, 0.915175f, 0.868934f, 0.825623f, 0.777405f, 0.720353f, 0.658341f, 0.593878f, 0.527963f, 0.461834f, 0.398057f, 0.339554f, 0.283493f, 0.228254f, 0.179828f, 0.140211f, 0.107633f, 0.081187f, 0.060281f, 0.044096f, 0.0318004f, 0.0226017f, 0.0159051f, 0.0111303f, 0.0077488f, 0.0053751f, 0.00371774f, 0.00256456f, 0.00176847f, 0.00122239f, 0.00084619f, 0.00058644f, 0.00040741f, 0.000284041f, 0.00019873f, 0.00013955f, 9.8428E-05f, 6.9819E-05f, 4.9737E-05f, 3.55405E-05f, 2.5486E-05f, 1.83384E-05f, 1.3249E-05f, 9.6196E-06f, 7.0128E-06f, 5.1298E-06f, 3.76473E-06f, 2.77081E-06f, 2.04613E-06f, 1.51677E-06f, 1.12809E-06f, 8.4216E-07f, 6.297E-07f };
const float CIEObserver::z[] = { 5.35027E-07f, 4.0283E-06f, 2.61437E-05f, 0.00014622f, 0.000704776f, 0.0029278f, 0.0104822f, 0.032344f, 0.0860109f, 0.19712f, 0.389366f, 0.65676f, 0.972542f, 1.2825f, 1.55348f, 1.7985f, 1.96728f, 2.0273f, 1.9948f, 1.9007f, 1.74537f, 1.5549f, 1.31756f, 1.0302f, 0.772125f, 0.5706f, 0.415254f, 0.302356f, 0.218502f, 0.159249f, 0.112044f, 0.082248f, 0.060709f, 0.04305f, 0.030451f, 0.020584f, 0.013676f, 0.007918f, 0.003988f, 0.001091f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f };