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
use thrift::adept::common::ChunkService;

# HELPER FUNCTIONS AND STRUCTURES

package thrift::adept::common::OpinionService_getPolarity_args;
use base qw(Class::Accessor);

sub new {
                                                                                    my $classname = shift;
                                                                                    my $self      = {};
                                                                                    my $vals      = shift || {};
                                                                                    return bless ($self, $classname);
}

sub getName {
                                                                                    return 'OpinionService_getPolarity_args';
                                                                                  }

sub read {
                                                                                    my ($self, $input) = @_;
                                                                                    my $xfer  = 0;
                                                                                    my $fname;
                                                                                    my $ftype = 0;
                                                                                    my $fid   = 0;
                                                                                    $xfer += $input->readStructBegin(\$fname);
                                                                                    while (1) 
                                                                                    {
                                                                                      $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                                                                                      if ($ftype == TType::STOP) {
                                                                                        last;
                                                                                      }
                                                                                      SWITCH: for($fid)
                                                                                      {
                                                                                          $xfer += $input->skip($ftype);
                                                                                      }
                                                                                      $xfer += $input->readFieldEnd();
                                                                                    }
                                                                                    $xfer += $input->readStructEnd();
                                                                                    return $xfer;
                                                                                  }

sub write {
                                                                                    my ($self, $output) = @_;
                                                                                    my $xfer   = 0;
                                                                                    $xfer += $output->writeStructBegin('OpinionService_getPolarity_args');
                                                                                    $xfer += $output->writeFieldStop();
                                                                                    $xfer += $output->writeStructEnd();
                                                                                    return $xfer;
                                                                                  }

package thrift::adept::common::OpinionService_getPolarity_result;
use base qw(Class::Accessor);
thrift::adept::common::OpinionService_getPolarity_result->mk_accessors( qw( success ) );

sub new {
                                                                                    my $classname = shift;
                                                                                    my $self      = {};
                                                                                    my $vals      = shift || {};
                                                                                    $self->{success} = undef;
                                                                                    if (UNIVERSAL::isa($vals,'HASH')) {
                                                                                      if (defined $vals->{success}) {
                                                                                        $self->{success} = $vals->{success};
                                                                                      }
                                                                                    }
                                                                                    return bless ($self, $classname);
}

sub getName {
                                                                                    return 'OpinionService_getPolarity_result';
                                                                                  }

sub read {
                                                                                    my ($self, $input) = @_;
                                                                                    my $xfer  = 0;
                                                                                    my $fname;
                                                                                    my $ftype = 0;
                                                                                    my $fid   = 0;
                                                                                    $xfer += $input->readStructBegin(\$fname);
                                                                                    while (1) 
                                                                                    {
                                                                                      $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                                                                                      if ($ftype == TType::STOP) {
                                                                                        last;
                                                                                      }
                                                                                      SWITCH: for($fid)
                                                                                      {
                                                                                        /^0$/ && do{                                                                                        if ($ftype == TType::I32) {
                                                                                          $xfer += $input->readI32(\$self->{success});
                                                                                        } else {
                                                                                          $xfer += $input->skip($ftype);
                                                                                        }
                                                                                        last; };
                                                                                          $xfer += $input->skip($ftype);
                                                                                      }
                                                                                      $xfer += $input->readFieldEnd();
                                                                                    }
                                                                                    $xfer += $input->readStructEnd();
                                                                                    return $xfer;
                                                                                  }

sub write {
                                                                                    my ($self, $output) = @_;
                                                                                    my $xfer   = 0;
                                                                                    $xfer += $output->writeStructBegin('OpinionService_getPolarity_result');
                                                                                    if (defined $self->{success}) {
                                                                                      $xfer += $output->writeFieldBegin('success', TType::I32, 0);
                                                                                      $xfer += $output->writeI32($self->{success});
                                                                                      $xfer += $output->writeFieldEnd();
                                                                                    }
                                                                                    $xfer += $output->writeFieldStop();
                                                                                    $xfer += $output->writeStructEnd();
                                                                                    return $xfer;
                                                                                  }

package thrift::adept::common::OpinionService_getSubjectivity_args;
use base qw(Class::Accessor);

sub new {
                                                                                    my $classname = shift;
                                                                                    my $self      = {};
                                                                                    my $vals      = shift || {};
                                                                                    return bless ($self, $classname);
}

sub getName {
                                                                                    return 'OpinionService_getSubjectivity_args';
                                                                                  }

sub read {
                                                                                    my ($self, $input) = @_;
                                                                                    my $xfer  = 0;
                                                                                    my $fname;
                                                                                    my $ftype = 0;
                                                                                    my $fid   = 0;
                                                                                    $xfer += $input->readStructBegin(\$fname);
                                                                                    while (1) 
                                                                                    {
                                                                                      $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                                                                                      if ($ftype == TType::STOP) {
                                                                                        last;
                                                                                      }
                                                                                      SWITCH: for($fid)
                                                                                      {
                                                                                          $xfer += $input->skip($ftype);
                                                                                      }
                                                                                      $xfer += $input->readFieldEnd();
                                                                                    }
                                                                                    $xfer += $input->readStructEnd();
                                                                                    return $xfer;
                                                                                  }

sub write {
                                                                                    my ($self, $output) = @_;
                                                                                    my $xfer   = 0;
                                                                                    $xfer += $output->writeStructBegin('OpinionService_getSubjectivity_args');
                                                                                    $xfer += $output->writeFieldStop();
                                                                                    $xfer += $output->writeStructEnd();
                                                                                    return $xfer;
                                                                                  }

package thrift::adept::common::OpinionService_getSubjectivity_result;
use base qw(Class::Accessor);
thrift::adept::common::OpinionService_getSubjectivity_result->mk_accessors( qw( success ) );

sub new {
                                                                                    my $classname = shift;
                                                                                    my $self      = {};
                                                                                    my $vals      = shift || {};
                                                                                    $self->{success} = undef;
                                                                                    if (UNIVERSAL::isa($vals,'HASH')) {
                                                                                      if (defined $vals->{success}) {
                                                                                        $self->{success} = $vals->{success};
                                                                                      }
                                                                                    }
                                                                                    return bless ($self, $classname);
}

sub getName {
                                                                                    return 'OpinionService_getSubjectivity_result';
                                                                                  }

sub read {
                                                                                    my ($self, $input) = @_;
                                                                                    my $xfer  = 0;
                                                                                    my $fname;
                                                                                    my $ftype = 0;
                                                                                    my $fid   = 0;
                                                                                    $xfer += $input->readStructBegin(\$fname);
                                                                                    while (1) 
                                                                                    {
                                                                                      $xfer += $input->readFieldBegin(\$fname, \$ftype, \$fid);
                                                                                      if ($ftype == TType::STOP) {
                                                                                        last;
                                                                                      }
                                                                                      SWITCH: for($fid)
                                                                                      {
                                                                                        /^0$/ && do{                                                                                        if ($ftype == TType::I32) {
                                                                                          $xfer += $input->readI32(\$self->{success});
                                                                                        } else {
                                                                                          $xfer += $input->skip($ftype);
                                                                                        }
                                                                                        last; };
                                                                                          $xfer += $input->skip($ftype);
                                                                                      }
                                                                                      $xfer += $input->readFieldEnd();
                                                                                    }
                                                                                    $xfer += $input->readStructEnd();
                                                                                    return $xfer;
                                                                                  }

sub write {
                                                                                    my ($self, $output) = @_;
                                                                                    my $xfer   = 0;
                                                                                    $xfer += $output->writeStructBegin('OpinionService_getSubjectivity_result');
                                                                                    if (defined $self->{success}) {
                                                                                      $xfer += $output->writeFieldBegin('success', TType::I32, 0);
                                                                                      $xfer += $output->writeI32($self->{success});
                                                                                      $xfer += $output->writeFieldEnd();
                                                                                    }
                                                                                    $xfer += $output->writeFieldStop();
                                                                                    $xfer += $output->writeStructEnd();
                                                                                    return $xfer;
                                                                                  }

package thrift::adept::common::OpinionServiceIf;

use strict;
use base qw(thrift::adept::common::ChunkServiceIf);

sub getPolarity{
  my $self = shift;

  die 'implement interface';
}

sub getSubjectivity{
  my $self = shift;

  die 'implement interface';
}

package thrift::adept::common::OpinionServiceRest;

use strict;
use base qw(thrift::adept::common::ChunkServiceRest);

sub getPolarity{
                                                                                    my ($self, $request) = @_;

                                                                                    return $self->{impl}->getPolarity();
                                                                                  }

sub getSubjectivity{
                                                                                    my ($self, $request) = @_;

                                                                                    return $self->{impl}->getSubjectivity();
                                                                                  }

package thrift::adept::common::OpinionServiceClient;

use base qw(thrift::adept::common::ChunkServiceClient);
use base qw(thrift::adept::common::OpinionServiceIf);
sub new {
                                                                                    my ($classname, $input, $output) = @_;
                                                                                    my $self      = {};
                                                                                    $self = $classname->SUPER::new($input, $output);
                                                                                    return bless($self,$classname);
}

sub getPolarity{
  my $self = shift;

                                                                                                                                                                        $self->send_getPolarity();
                                                                                    return $self->recv_getPolarity();
}

sub send_getPolarity{
  my $self = shift;

                                                                                    $self->{output}->writeMessageBegin('getPolarity', TMessageType::CALL, $self->{seqid});
                                                                                    my $args = new thrift::adept::common::OpinionService_getPolarity_args();
                                                                                    $args->write($self->{output});
                                                                                    $self->{output}->writeMessageEnd();
                                                                                    $self->{output}->getTransport()->flush();
}

sub recv_getPolarity{
  my $self = shift;

                                                                                    my $rseqid = 0;
                                                                                    my $fname;
                                                                                    my $mtype = 0;

                                                                                    $self->{input}->readMessageBegin(\$fname, \$mtype, \$rseqid);
                                                                                    if ($mtype == TMessageType::EXCEPTION) {
                                                                                      my $x = new TApplicationException();
                                                                                      $x->read($self->{input});
                                                                                      $self->{input}->readMessageEnd();
                                                                                      die $x;
                                                                                    }
                                                                                    my $result = new thrift::adept::common::OpinionService_getPolarity_result();
                                                                                    $result->read($self->{input});
                                                                                    $self->{input}->readMessageEnd();

                                                                                    if (defined $result->{success} ) {
                                                                                      return $result->{success};
                                                                                    }
                                                                                    die "getPolarity failed: unknown result";
}
sub getSubjectivity{
  my $self = shift;

                                                                                                                                                                        $self->send_getSubjectivity();
                                                                                    return $self->recv_getSubjectivity();
}

sub send_getSubjectivity{
  my $self = shift;

                                                                                    $self->{output}->writeMessageBegin('getSubjectivity', TMessageType::CALL, $self->{seqid});
                                                                                    my $args = new thrift::adept::common::OpinionService_getSubjectivity_args();
                                                                                    $args->write($self->{output});
                                                                                    $self->{output}->writeMessageEnd();
                                                                                    $self->{output}->getTransport()->flush();
}

sub recv_getSubjectivity{
  my $self = shift;

                                                                                    my $rseqid = 0;
                                                                                    my $fname;
                                                                                    my $mtype = 0;

                                                                                    $self->{input}->readMessageBegin(\$fname, \$mtype, \$rseqid);
                                                                                    if ($mtype == TMessageType::EXCEPTION) {
                                                                                      my $x = new TApplicationException();
                                                                                      $x->read($self->{input});
                                                                                      $self->{input}->readMessageEnd();
                                                                                      die $x;
                                                                                    }
                                                                                    my $result = new thrift::adept::common::OpinionService_getSubjectivity_result();
                                                                                    $result->read($self->{input});
                                                                                    $self->{input}->readMessageEnd();

                                                                                    if (defined $result->{success} ) {
                                                                                      return $result->{success};
                                                                                    }
                                                                                    die "getSubjectivity failed: unknown result";
}
package thrift::adept::common::OpinionServiceProcessor;

use strict;
use base qw(thrift::adept::common::ChunkServiceProcessor);

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

sub process_getPolarity {
                                                                                      my ($self, $seqid, $input, $output) = @_;
                                                                                      my $args = new thrift::adept::common::OpinionService_getPolarity_args();
                                                                                      $args->read($input);
                                                                                      $input->readMessageEnd();
                                                                                      my $result = new thrift::adept::common::OpinionService_getPolarity_result();
                                                                                      $result->{success} = $self->{handler}->getPolarity();
                                                                                      $output->writeMessageBegin('getPolarity', TMessageType::REPLY, $seqid);
                                                                                      $result->write($output);
                                                                                      $output->writeMessageEnd();
                                                                                      $output->getTransport()->flush();
}

sub process_getSubjectivity {
                                                                                      my ($self, $seqid, $input, $output) = @_;
                                                                                      my $args = new thrift::adept::common::OpinionService_getSubjectivity_args();
                                                                                      $args->read($input);
                                                                                      $input->readMessageEnd();
                                                                                      my $result = new thrift::adept::common::OpinionService_getSubjectivity_result();
                                                                                      $result->{success} = $self->{handler}->getSubjectivity();
                                                                                      $output->writeMessageBegin('getSubjectivity', TMessageType::REPLY, $seqid);
                                                                                      $result->write($output);
                                                                                      $output->writeMessageEnd();
                                                                                      $output->getTransport()->flush();
}

1;