// Code generated by Stan version 2.21.0

#include <stan/model/model_header.hpp>

namespace noname_model_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "/home/travis/build/arviz-devs/ArviZ.jl/docs/build/tmp/noname.stan");
    reader.add_event(29, 27, "end", "/home/travis/build/arviz-devs/ArviZ.jl/docs/build/tmp/noname.stan");
    return reader;
}

class noname_model
  : public stan::model::model_base_crtp<noname_model> {
private:
        int J;
        std::vector<double> y;
        std::vector<double> sigma;
public:
    noname_model(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }

    noname_model(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "noname_model_namespace::noname_model";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            // initialize data block variables from context__
            current_statement_begin__ = 2;
            context__.validate_dims("data initialization", "J", "int", context__.to_vec());
            J = int(0);
            vals_i__ = context__.vals_i("J");
            pos__ = 0;
            J = vals_i__[pos__++];
            check_greater_or_equal(function__, "J", J, 0);

            current_statement_begin__ = 3;
            validate_non_negative_index("y", "J", J);
            context__.validate_dims("data initialization", "y", "double", context__.to_vec(J));
            y = std::vector<double>(J, double(0));
            vals_r__ = context__.vals_r("y");
            pos__ = 0;
            size_t y_k_0_max__ = J;
            for (size_t k_0__ = 0; k_0__ < y_k_0_max__; ++k_0__) {
                y[k_0__] = vals_r__[pos__++];
            }

            current_statement_begin__ = 4;
            validate_non_negative_index("sigma", "J", J);
            context__.validate_dims("data initialization", "sigma", "double", context__.to_vec(J));
            sigma = std::vector<double>(J, double(0));
            vals_r__ = context__.vals_r("sigma");
            pos__ = 0;
            size_t sigma_k_0_max__ = J;
            for (size_t k_0__ = 0; k_0__ < sigma_k_0_max__; ++k_0__) {
                sigma[k_0__] = vals_r__[pos__++];
            }
            size_t sigma_i_0_max__ = J;
            for (size_t i_0__ = 0; i_0__ < sigma_i_0_max__; ++i_0__) {
                check_greater_or_equal(function__, "sigma[i_0__]", sigma[i_0__], 0);
            }


            // initialize transformed data variables
            // execute transformed data statements

            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 8;
            num_params_r__ += 1;
            current_statement_begin__ = 9;
            num_params_r__ += 1;
            current_statement_begin__ = 10;
            validate_non_negative_index("theta", "J", J);
            num_params_r__ += (1 * J);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~noname_model() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        current_statement_begin__ = 8;
        if (!(context__.contains_r("mu")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable mu missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("mu");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "mu", "double", context__.to_vec());
        double mu(0);
        mu = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(mu);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable mu: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        current_statement_begin__ = 9;
        if (!(context__.contains_r("tau")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable tau missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("tau");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "tau", "double", context__.to_vec());
        double tau(0);
        tau = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, tau);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable tau: ") + e.what()), current_statement_begin__, prog_reader__());
        }

        current_statement_begin__ = 10;
        if (!(context__.contains_r("theta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable theta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("theta");
        pos__ = 0U;
        validate_non_negative_index("theta", "J", J);
        context__.validate_dims("parameter initialization", "theta", "double", context__.to_vec(J));
        std::vector<double> theta(J, double(0));
        size_t theta_k_0_max__ = J;
        for (size_t k_0__ = 0; k_0__ < theta_k_0_max__; ++k_0__) {
            theta[k_0__] = vals_r__[pos__++];
        }
        size_t theta_i_0_max__ = J;
        for (size_t i_0__ = 0; i_0__ < theta_i_0_max__; ++i_0__) {
            try {
                writer__.scalar_unconstrain(theta[i_0__]);
            } catch (const std::exception& e) {
                stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable theta: ") + e.what()), current_statement_begin__, prog_reader__());
            }
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);

            // model parameters
            current_statement_begin__ = 8;
            local_scalar_t__ mu;
            (void) mu;  // dummy to suppress unused var warning
            if (jacobian__)
                mu = in__.scalar_constrain(lp__);
            else
                mu = in__.scalar_constrain();

            current_statement_begin__ = 9;
            local_scalar_t__ tau;
            (void) tau;  // dummy to suppress unused var warning
            if (jacobian__)
                tau = in__.scalar_lb_constrain(0, lp__);
            else
                tau = in__.scalar_lb_constrain(0);

            current_statement_begin__ = 10;
            std::vector<local_scalar_t__> theta;
            size_t theta_d_0_max__ = J;
            theta.reserve(theta_d_0_max__);
            for (size_t d_0__ = 0; d_0__ < theta_d_0_max__; ++d_0__) {
                if (jacobian__)
                    theta.push_back(in__.scalar_constrain(lp__));
                else
                    theta.push_back(in__.scalar_constrain());
            }

            // model body

            current_statement_begin__ = 14;
            lp_accum__.add(normal_log<propto__>(mu, 0, 5));
            current_statement_begin__ = 15;
            lp_accum__.add(cauchy_log<propto__>(tau, 0, 5));
            current_statement_begin__ = 16;
            lp_accum__.add(normal_log<propto__>(theta, mu, tau));
            current_statement_begin__ = 17;
            lp_accum__.add(normal_log<propto__>(y, theta, sigma));

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("mu");
        names__.push_back("tau");
        names__.push_back("theta");
        names__.push_back("log_lik");
        names__.push_back("y_hat");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(J);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(J);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(J);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "noname_model_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning

        // read-transform, write parameters
        double mu = in__.scalar_constrain();
        vars__.push_back(mu);

        double tau = in__.scalar_lb_constrain(0);
        vars__.push_back(tau);

        std::vector<double> theta;
        size_t theta_d_0_max__ = J;
        theta.reserve(theta_d_0_max__);
        for (size_t d_0__ = 0; d_0__ < theta_d_0_max__; ++d_0__) {
            theta.push_back(in__.scalar_constrain());
        }
        size_t theta_k_0_max__ = J;
        for (size_t k_0__ = 0; k_0__ < theta_k_0_max__; ++k_0__) {
            vars__.push_back(theta[k_0__]);
        }

        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        if (!include_tparams__ && !include_gqs__) return;

        try {
            if (!include_gqs__ && !include_tparams__) return;
            if (!include_gqs__) return;
            // declare and define generated quantities
            current_statement_begin__ = 21;
            validate_non_negative_index("log_lik", "J", J);
            Eigen::Matrix<double, Eigen::Dynamic, 1> log_lik(J);
            stan::math::initialize(log_lik, DUMMY_VAR__);
            stan::math::fill(log_lik, DUMMY_VAR__);

            current_statement_begin__ = 22;
            validate_non_negative_index("y_hat", "J", J);
            Eigen::Matrix<double, Eigen::Dynamic, 1> y_hat(J);
            stan::math::initialize(y_hat, DUMMY_VAR__);
            stan::math::fill(y_hat, DUMMY_VAR__);

            // generated quantities statements
            current_statement_begin__ = 23;
            for (int j = 1; j <= J; ++j) {

                current_statement_begin__ = 24;
                stan::model::assign(log_lik, 
                            stan::model::cons_list(stan::model::index_uni(j), stan::model::nil_index_list()), 
                            normal_log(get_base1(y, j, "y", 1), get_base1(theta, j, "theta", 1), get_base1(sigma, j, "sigma", 1)), 
                            "assigning variable log_lik");
                current_statement_begin__ = 25;
                stan::model::assign(y_hat, 
                            stan::model::cons_list(stan::model::index_uni(j), stan::model::nil_index_list()), 
                            normal_rng(get_base1(theta, j, "theta", 1), get_base1(sigma, j, "sigma", 1), base_rng__), 
                            "assigning variable y_hat");
            }

            // validate, write generated quantities
            current_statement_begin__ = 21;
            size_t log_lik_j_1_max__ = J;
            for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
                vars__.push_back(log_lik(j_1__));
            }

            current_statement_begin__ = 22;
            size_t y_hat_j_1_max__ = J;
            for (size_t j_1__ = 0; j_1__ < y_hat_j_1_max__; ++j_1__) {
                vars__.push_back(y_hat(j_1__));
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    std::string model_name() const {
        return "noname_model";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "tau";
        param_names__.push_back(param_name_stream__.str());
        size_t theta_k_0_max__ = J;
        for (size_t k_0__ = 0; k_0__ < theta_k_0_max__; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "theta" << '.' << k_0__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }

        if (!include_gqs__) return;
        size_t log_lik_j_1_max__ = J;
        for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "log_lik" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t y_hat_j_1_max__ = J;
        for (size_t j_1__ = 0; j_1__ < y_hat_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "y_hat" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "tau";
        param_names__.push_back(param_name_stream__.str());
        size_t theta_k_0_max__ = J;
        for (size_t k_0__ = 0; k_0__ < theta_k_0_max__; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "theta" << '.' << k_0__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }

        if (!include_gqs__) return;
        size_t log_lik_j_1_max__ = J;
        for (size_t j_1__ = 0; j_1__ < log_lik_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "log_lik" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t y_hat_j_1_max__ = J;
        for (size_t j_1__ = 0; j_1__ < y_hat_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "y_hat" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
    }

}; // model

}  // namespace

typedef noname_model_namespace::noname_model stan_model;

#ifndef USING_R

stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}

#endif

