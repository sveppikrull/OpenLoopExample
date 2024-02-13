def ExplicitEuler(fun, x, t, dt, Ns, p):
    
    for i in range(Ns):
        # ExplicitEuler step
        x[:,i + 1] = x[:,i] + fun(t[i],x[:,i],p)*dt
        # Update time
        t[i + 1] = t[i] + dt
