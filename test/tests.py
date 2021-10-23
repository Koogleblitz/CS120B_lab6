# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).
tests = [ 
    
    {
        'description': '1 release, toggle off',
        'steps': 
            [ 
                
                {'inputs': [('PINA', 1)],'iterations': 1, 'expected': [('PORTB',1)]}, # Set PIN to val then run one iteration
       
            ],
        'expected': [('PORTB',1)],
    },

#--------------------------------------------------------------------------------------

    {
        'description': '2 release, toggle off ',
        'steps': 
            [ 
                
                {'inputs': [('PINA', 1)],'iterations': 1, 'expected': [('PORTB',2)]}, # Set PIN to val then run one iteration
       
            ],
        'expected': [('PORTB',2)],
    },

#--------------------------------------------------------------------------------------

{
        'description': '3 release, toggle off',
        'steps': 
            [ 
                
                {'inputs': [('PINA', 1)],'iterations': 1, 'expected': [('PORTB',4)]}, # Set PIN to val then run one iteration
       
            ],
        'expected': [('PORTB',4)],
    },

#--------------------------------------------------------------------------------------

    {
        'description': '4 press, toggle on ',
        'steps': 
            [ 
                
                {'inputs': [('PINA', 0)],'iterations': 1, 'expected': [('PORTB',4)]}, # Set PIN to val then run one iteration
       
            ],
        'expected': [('PORTB',4)],
    },

#--------------------------------------------------------------------------------------
    {
        'description': '5 release, toggle still on ',
        'steps': 
            [ 
                
                {'inputs': [('PINA', 1)],'iterations': 1, 'expected': [('PORTB',4)]}, # Set PIN to val then run one iteration
       
            ],
        'expected': [('PORTB',4)],
    },

#--------------------------------------------------------------------------------------
{
        'description': '6 release, toggle still on ',
        'steps': 
            [ 
                
                {'inputs': [('PINA', 1)],'iterations': 1, 'expected': [('PORTB',4)]}, # Set PIN to val then run one iteration
       
            ],
        'expected': [('PORTB',4)],
    },

#--------------------------------------------------------------------------------------
{
        'description': '7 press, toggle off ',
        'steps': 
            [ 
                
                {'inputs': [('PINA', 0)],'iterations': 1, 'expected': [('PORTB',4)]}, # Set PIN to val then run one iteration
       
            ],
        'expected': [('PORTB',4)],
    },

#--------------------------------------------------------------------------------------
{
        'description': '8 release, toggle still off, restart cycle ',
        'steps': 
            [ 
                
                {'inputs': [('PINA', 1)],'iterations': 1, 'expected': [('PORTB',1)]}, # Set PIN to val then run one iteration
       
            ],
        'expected': [('PORTB',1)],
},

#--------------------------------------------------------------------------------------
{
        'description': '9 release , toggle still off ',
        'steps': 
            [ 
                
                {'inputs': [('PINA', 1)],'iterations': 1, 'expected': [('PORTB',2)]}, # Set PIN to val then run one iteration
       
            ],
        'expected': [('PORTB',2)],
    },

#--------------------------------------------------------------------------------------
    



#    {
#       'description': 'its about time. worry about this one later',
#        'steps': 
#            [ 
#                {'inputs': [('PINA',0)], 'time': 300, 'expected': [('PORTB',1)]},
#                {'inputs': [('PINA',0)], 'time': 1000, 'expected': [('PORTB',2)]},
#                {'inputs': [('PINA',0)], 'time': 1000, 'expected': [('PORTB',4)]},
#                {'inputs': [('PINA',0)], 'time': 1000, 'expected': [('PORTB',1)]},
#                {'inputs': [('PINA',0)], 'time': 1000, 'expected': [('PORTB',2)]},
#                
#            ],
#        'expected': [('PORTB',2)],
#    },

#--------------------------------------------------------------------------------------










]

watch = ['out','PORTB','state','prev','PORTA','toggle','restart']


# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
#watch = ['<function>::<static-var>','PORTB']

