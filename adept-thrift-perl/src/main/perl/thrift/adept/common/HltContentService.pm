#
# Autogenerated by Thrift Compiler (0.9.0)
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#
require 5.6.0;
use strict;
use warnings;
use Thrift;

use thrift::adept::common::Types;
use thrift::adept::common::ItemService;

# HELPER FUNCTIONS AND STRUCTURES

package thrift::adept::common::HltContentServiceIf;

use strict;
use base qw(thrift::adept::common::ItemServiceIf);

package thrift::adept::common::HltContentServiceRest;

use strict;
use base qw(thrift::adept::common::ItemServiceRest);

package thrift::adept::common::HltContentServiceClient;

use base qw(thrift::adept::common::ItemServiceClient);
use base qw(thrift::adept::common::HltContentServiceIf);
sub new {
                            my ($classname, $input, $output) = @_;
                            my $self      = {};
                            $self = $classname->SUPER::new($input, $output);
                            return bless($self,$classname);
}

package thrift::adept::common::HltContentServiceProcessor;

use strict;
use base qw(thrift::adept::common::ItemServiceProcessor);

sub process {
                              my ($self, $input, $output) = @_;
                              my $rseqid = 0;
                              my $fname  = undef;
                              my $mtype  = 0;

                              $input->readMessageBegin(\$fname, \$mtype, \$rseqid);
                              my $methodname = 'process_'.$fname;
                              if (!$self->can($methodname)) {
                                $input->skip(TType::STRUCT);
                                $input->readMessageEnd();
                                my $x = new TApplicationException('Function '.$fname.' not implemented.', TApplicationException::UNKNOWN_METHOD);
                                $output->writeMessageBegin($fname, TMessageType::EXCEPTION, $rseqid);
                                $x->write($output);
                                $output->writeMessageEnd();
                                $output->getTransport()->flush();
                                return;
                              }
                              $self->$methodname($rseqid, $input, $output);
                              return 1;
}

1;
