#include "tools.h"
#include <iostream>

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
   * TODO: Calculate the RMSE here.
   */
  VectorXd rmse(4);
  rmse << 0,0,0,0;

  // TODO: YOUR CODE HERE
  // check the validity of the following inputs:
  //  * the estimation vector size should not be zero
  //  * the estimation vector size should equal ground truth vector size
  if((estimations.size()!=ground_truth.size())
     ||(estimations.size()==0)
     ||(ground_truth.size()==0))
     {
         return rmse;
     }
  // TODO: accumulate squared residuals
  for (int i=0; i < estimations.size(); ++i) {
    VectorXd residual = estimations[i] - ground_truth[i];

    // coefficient-wise multiplication
    residual = residual.array()*residual.array();
    rmse += residual;
  }
  
  // TODO: calculate the mean

  rmse = rmse/estimations.size();
  // TODO: calculate the squared root
  rmse = rmse.array().sqrt();
  // return the result
  return rmse;
}

MatrixXd Tools::CalculateJacobian(const VectorXd& x_state) {
  /**
   * TODO:
   * Calculate a Jacobian here.
   */
  MatrixXd Hj(3,4);
  // recover state parameters
  float px = x_state(0);
  float py = x_state(1);
  float vx = x_state(2);
  float vy = x_state(3);

  // TODO: YOUR CODE HERE 

  // check division by zero
  float p_2 = px*px+py*py;
  float p_2_sqrt = sqrt(px*px+py*py);
  if( p_2 == 0)
  {
      return Hj;
  }
  // compute the Jacobian matrix
  Hj << px / p_2_sqrt,                   py / p_2_sqrt,                             0,           0,
        -py/p_2,                         px/p_2,                                    0,           0,
        py*(vx*py-vy*px)/(p_2_sqrt*p_2), px*(vy*px-vx*py)/(p_2_sqrt*p_2), px/p_2_sqrt, py/p_2_sqrt;
  return Hj;
}
